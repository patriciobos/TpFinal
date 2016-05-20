#!/usr/bin/perl

open(OUTPUT, "> fsdata.c");

chdir("Website");

opendir(DIR, ".");
@files =  grep { !/^\./ && !/(CVS|~)/ } readdir(DIR);
closedir(DIR);

foreach $file (@files) {  
   
    if(-d $file && $file !~ /^\./) {
	print "Processing directory $file\n";
	opendir(DIR, $file);
	@newfiles =  grep { !/^\./ && !/(CVS|~)/ } readdir(DIR);
	closedir(DIR);
	printf "Adding files @newfiles\n";
	@files = (@files, map { $_ = "$file/$_" } @newfiles);
	next;
    }
}

printf(OUTPUT "#include \"fs.h\"\n");
printf(OUTPUT "#include \"lwip/def.h\"\n");
printf(OUTPUT "#include \"fsdata.h\"\n\n");

printf(OUTPUT "#define file_NULL (struct fsdata_file *) NULL\n\n");

$counter = 0;

foreach $file (@files) {
    if(-f $file) {
	
	print "Adding file $file\n";
	
	open(FILE, $file) || die "Could not open file $file\n";

	$file =~ s-^-/-;
	$fvar = $file;
	$fvar =~ s-/-_-g;
	$fvar =~ s-\.-_-g;
	# for AVR, add PROGMEM here
	print(OUTPUT "static const unsigned int dummy".$fvar." = ".$counter.";\n");
	print(OUTPUT "static const unsigned char data".$fvar."[] = {\n");
	print(OUTPUT "\t/* $file */\n\t");
	for($j = 0; $j < length($file); $j++) {
	    printf(OUTPUT "%#02x, ", unpack("C", substr($file, $j, 1)));
	}
	printf(OUTPUT "0,\n");
	
	$counter = $counter + 1;
	
	$i = 0;        
	while(read(FILE, $data, 1)) {
	    if($i == 0) {
		print(OUTPUT "\t");
	    }
	    printf(OUTPUT "%#02x, ", unpack("C", $data));
	    
		#$i++;
	    #if($i == 10) {
		#	print(OUTPUT "\n");
		#	$i = 0;
	    #}
	}
	print(OUTPUT "};\n\n");
	close(FILE);
	push(@fvars, $fvar);
	push(@pfiles, $file);
    }
}

for($i = 0; $i < @fvars; $i++) {
    $file = $pfiles[$i];
    $fvar = $fvars[$i];

    if($i == 0) {
        $prevfile = "file_NULL";
    } else {
        $prevfile = "file" . $fvars[$i - 1];
    }
    print(OUTPUT "const struct fsdata_file file".$fvar."[] = {{$prevfile, data$fvar, ");
    print(OUTPUT "data$fvar + ". (length($file) + 1) .", ");
    print(OUTPUT "sizeof(data$fvar) - ". (length($file) + 1) .",1}};\n\n");
}

print(OUTPUT "#define FS_ROOT file$fvars[$i - 1]\n\n");
print(OUTPUT "#define FS_NUMFILES $i\n");

	