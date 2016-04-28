@echo off

set DirDESTINO=E:\FAKU\Sistemas_Embebidos\WORKSPACES\CAPEAR_EM\RDB1768cmsis2_uIP\apps\webserver\httpd-fs
set FILE1=indexpanel
set FILE2=indexconfig
set FILE3=indexgate
set FILEX=index

::TRANSFORMACION_PARA_LPC
_Website4uIP.exe _%FILE1%
if errorlevel 1 goto YERRO
_Website4uIP.exe _%FILE2%
if errorlevel 1 goto YERRO
_Website4uIP.exe _%FILE3%
if errorlevel 1 goto YERRO1

::CORRECCION_LINKS_PARA_LPC (importante que venga DESPUES de lo de arriba!)
ren %FILE1%.html %FILE1%.fart
ren %FILE2%.html %FILE2%.fart
ren %FILE3%.html %FILE3%.fart
copy _%FILEX%.html %FILEX%.fart
_fart.exe *.fart 	"a href=\"_"		"a href=\""
_fart.exe *.fart 	"action=\"_"		"action=\""
_fart.exe *.fart 	"iframe src=\"_"	"iframe src=\""
ren *.fart *.html

::COPIA_ARCHIVOS_EN_DESTINO
del /F /Q "%DirDESTINO%\*.*"
move /Y %FILE1%.html "%DirDESTINO%\"
move /Y %FILE2%.html "%DirDESTINO%\"
move /Y %FILE3%.html "%DirDESTINO%\"
move /Y %FILEX%.html "%DirDESTINO%\"
dir /b /a-d "*.*"|findstr /B "_" >"_files.excluded"
xcopy "*.*" "%DirDESTINO%\" /exclude:_files.excluded /y

set DirORIGINAL=%cd%

::EJECUTA_PERL
cd /D "%DirDESTINO%"
cd ..
echo.
perl makefsdata

cd /D "%DirORIGINAL%"

echo.
echo           *** Todo de maravillas ***
goto FIN

:YERRO1
echo.
echo Hubo error al convertir el website a micro IP, 
echo Asegurate que esten todos los 3 archivos principales
echo y su nombre empiece con el _ ("underscore")
echo.
echo %0 ABORTADO!
goto FIN

:YERRO2
echo.
echo Hubo error al pasar el FART (FIND AND REPLACE). 
echo Asegurate que los archivos afectados no se hayan arruinado.
echo.
echo %0 ABORTADO!
goto FIN

:FIN
echo.
pause
