


/*
========================================================

****   PROYECTO CAPEAR - Programas "browser-side"  *****

========================================================
*/


/* VARIABLES GLOBALES */

//Primer y ultimo puertos
PRT_pri=1;	/*  1 ó 0  */
PRT_ulh=4;	/*  <=ult  */
PRT_ult=8;	/*  max.8  */

//valores por defecto y cotas
var HR_ONdef='00:00';
var HR_OFdef='23:59';
var RDLAYdef='30';		RDLAYmin=1;	RDLAYmax=30;
var IP___def='255.255.255.255';
var RPERIdef='5';		RPERImin=2;	RPERImax=99;
var RTRIGdef='1';		RTRIGmin=1;	RTRIGmax=5;

//señaladores de error
var vHR_ON=1;
var vHR_OF=1;
var vHR_ID=1;
var vRDLAY=1;
var vIP___=1;
var vRPERI=1;
var vRTRIG=1;

//variables de validación
var todo_ok=false;

//Otras variables
var FONDO=0;

//Mensajes
var MSJ_VAL_VALIDO='Por favor, ingresar un valor válido.';

//Ayudas: común
var aX1='\n\nValores admitidos: ';var aX2=' a ';var aX3=' (sugerido: ';var aX4=')\n';
//Ayudas: individual
var aACTPT='** Habilitar puerto **\n\nPermite que se tome control del puerto y se lo pueda programar.\nSi se deshabilita, el puerto queda en estado "siempre encendido".\n\n';
var aSTATU='** Estado actual del puerto **\n\nInforma el estado actual del puerto:\n ON:   Encendido\n OFF: Apagado\n N/D:  No Disponible\n\n';
var aSWMAN='** Conmutador manual **\n\nPermite forzar la conexión o desconexión de corriente\nen forma manual desde esta interfaz web.\n\n';
	AUX='** Modo Real Time Clock **\n\nPermite programar el puerto en función de la hora del día.\n\nOn/Off: programar una hora de encendido y una hora de apagado\n';
var aRTCMD=AUX+'Reset: programar una hora de reinicio.\n\n';
var aHR_ON='** Hora ON **\n\nHora en la que será encendido el puerto.\n\n';
var aHR_OF='** Hora OFF/Reset **\n\nSi modo RTC=On/Off: Hora en la que será apagado el puerto.\n\nSi modo RTC=Reset: Hora en la que será reiniciado el puerto.\n\n';
var aRDLAY='** Duración del reinicio **\n\nEl tiempo que se mantendrá el estado "OFF" en un\npuerto que está siendo reiniciado (en segundos).'+aX1+RDLAYmin+aX2+RDLAYmax+aX3+RDLAYdef+aX4;
var aRAUTO='** Reinicio automático **\n\nSi se habilita, el puerto será automáticamente reiniciado toda vez que el\nPING hacia la dirección IP asociada al puerto no reciba una respuesta.\n\n';
	AUX='** Dirección IP asociada al puerto **\n\nSi AutoRST está activado, cuando no se reciba respuesta PING\nde esta dirección IP, el puerto se apagará y luego re-encenderá\n\n';
	AUX=AUX+'NOTA:\nObsérvese que es posible disociar el equipo realmente enchufado\nen el puerto, de aquel cuya dirección IP se está monitoreando.\n';
var aIP___=AUX+'De este modo, podría programarse que la falta de respuesta de\nun equipo "A" dispare el reinicio de un equipo "B" diferente.\n\n';
var aRPERI='** Intervalo entre PINGs **\n\nDetermina el tiempo de guarda entre la emisión de 2\nPING ECHO REQUEST sucesivos (en segundos).'+aX1+RPERImin+aX2+RPERImax+aX3+RPERIdef+aX4;
var aRTRIG='** Cantidad de fallos que disparan un reinicio **\n\nDetermina cuántos PINGs sucesivos sin respuesta\nse necesitan para proceder con el reinicio del puerto.'+aX1+RTRIGmin+aX2+RTRIGmax+aX3+RTRIGdef+aX4;


/* FUNCIONES COMUNES */

function JavaScriptEnabled()	// saca el cartel destinado a los que no soportan JavaScript
{
	document.getElementById('NoJavaScript').style.display='none';
	return;
	}


function obtener_browser_cliente()	//devuelve un vector con browser[0] y version[1]
{
	navigator.sayswho= (function(){
		var N= navigator.appName, ua= navigator.userAgent, tem;
		var M= ua.match(/(opera|chrome|safari|firefox|msie)\/?\s*(\.?\d+(\.\d+)*)/i);
		if(M && (tem= ua.match(/version\/([\.\d]+)/i))!= null) M[2]= tem[1];
		M= M? [M[1], M[2]]: [N, navigator.appVersion, '-?'];
		return M; //divisible en M[0]:browser y M[1]:version
		})();
	//DEPU	alert(navigator.sayswho[0]+' / '+navigator.sayswho[1]);
	return navigator.sayswho;
	}


function habilitar_config(SN)	//SN es 1 o 0
{
	if (SN==0)	document.getElementById('config').style.display='none'
	      else	document.getElementById('config').style.display='inline-block';
	return;
	}


function boton_aplicar()
{
	var L='';

L=L+'	<table id="del_boton"><th>';
L=L+'	<input type="button" name="LISTO" id="submit" onMouseEnter="verifica_datos_todos(0);" />';	
L=L+'	</th></table>';

	/* Uso "LISTO" en vez de "submit" pues anda igual */

	return L;
	}


function switch_debug()
{
	if (document.getElementById('iframe').style.display=='none') {
		document.getElementById('iframe').style.display='inline';
	//	alert('Estas usando:\n\n'+obtener_browser_cliente()[0]+' v'+obtener_browser_cliente()[1]);
		}
	else
		document.getElementById('iframe').style.display='none';
	return;
	}


/* FUNCIONES PARTICULARES */

function habilitar_puerto(N)	//N es el # de puerto
{
	var VACTPT=document.getElementById('ACTPT'+N).checked;
	if(VACTPT!=true) {	//deshabilito
		document.getElementById('STATU'+N).setAttribute('style','color:#ACA899');		
		document.getElementById('STATU'+N).innerHTML="N/A";		
		document.getElementById('SWMAN'+N).disabled=true;		
		document.getElementById('RTCMD'+N).disabled=true;		
		document.getElementById('HR_ON'+N).disabled=true;		
		document.getElementById('HR_OF'+N).disabled=true;		
		document.getElementById('RDLAY'+N).disabled=true;		
		document.getElementById('RAUTO'+N).disabled=true;		
		document.getElementById('IP___'+N).disabled=true;		
		document.getElementById('RPERI'+N).disabled=true;		
		document.getElementById('RTRIG'+N).disabled=true;		
		} else {	//habilito
		document.getElementById('STATU'+N).setAttribute('style','color:#000000');		
		document.getElementById('STATU'+N).innerHTML="ON";	/*	CAPEAR v2013.10.27 (no mas N/D ni N/A)	Antes: N/D	*/
		document.getElementById('SWMAN'+N).disabled=false;		
		document.getElementById('RTCMD'+N).disabled=false;		
		/* HR_ON, HR_OF, RDLAY				*/
	 	document.getElementById('RAUTO'+N).disabled=false;		
		/* RPERI, RTRIG 				*/
		}
	return;
	}


function seleccion_de_modos(N)	//N es el # de puerto
{
	var VRTCMD=document.getElementById('RTCMD'+N).value;
	var VRAUTO=document.getElementById('RAUTO'+N).checked;
	switch(VRTCMD) {
		case 'DESAC':
			document.getElementById('HR_ON'+N).disabled=true;					
			document.getElementById('HR_OF'+N).disabled=true;		
			document.getElementById('RDLAY'+N).disabled=!VRAUTO;
			break;
		case 'ONOFF':
			document.getElementById('HR_ON'+N).disabled=false;					
			document.getElementById('HR_OF'+N).disabled=false;		
			document.getElementById('RDLAY'+N).disabled=!VRAUTO;
			break;
		case 'RESET':
			document.getElementById('HR_ON'+N).disabled=true;					
			document.getElementById('HR_OF'+N).disabled=false;		
			document.getElementById('RDLAY'+N).disabled=false;
			break;
		}
		document.getElementById('IP___'+N).disabled=!VRAUTO;		
		document.getElementById('RPERI'+N).disabled=!VRAUTO;
		document.getElementById('RTRIG'+N).disabled=!VRAUTO;
	return;
	}


function truchar_estado(N)      //N es el # de puerto
{
        document.getElementById('STATU'+N).setAttribute('style','color:#000000');
        var VSTAT=document.getElementById('STATU'+N).innerHTML;
		//DEPU alert('VSTAT='+VSTAT);
        if(VSTAT=='OFF') {
                document.getElementById('SWMAN'+N).value='APAGAR';	/* CAPEAR v2.09.03+ //Lógica invertida */     
                document.getElementById('STATU'+N).innerHTML='ON';
                } else {
                document.getElementById('SWMAN'+N).value='PRENDER';	/* CAPEAR v2.09.03+ //Lógica invertida */              
                document.getElementById('STATU'+N).innerHTML='OFF';
                }
        return;
        }


function conmutar_estado(N)	//N es el # de puerto
{
	var rnd=Math.random();
	truchar_estado(N);
	cgi_frame='p'+N+'sw.shtml?anticache='+rnd;
	estado_frame='p'+N+'estado.shtml?anticache='+rnd;
//debug	alert(cgi_frame);alert(estado_frame);
 	window.open(cgi_frame,'cgi');
	window.open(estado_frame,'estado'+N);
	return;
	}


function listar_puerto(N)	//N es el # de puerto
{
	var L='';

L=L+'	<!--Puerto# '+N+' -->																';
L=L+'																			';
L=L+'	<tr class="linea" onChange="verifica_datos_ingresados('+N+'); verifica_datos_todos(0);" >													';	/* CAPEAR v2.10.16+ //Quito: 	onMouseMove="verifica_datos_todos(0);" */
L=L+'																			';
L=L+'	<th class="ACTPT">'+N+' <input type="checkbox" name="ACTPT'+N+'" id="ACTPT'+N+'" onClick="habilitar_puerto('+N+');" '; if (N>PRT_ulh) L=L+'disabled '; L=L+' />';	/* CAPEAR v2.10.14+ //No permito habilitar mas de 5 puertos */
L=L+'		</th>																	';
L=L+'	<th><span id="STATU'+N+'" class="STATU">ON</span>																							';	/* CAPEAR v2013.10.27 (no mas N/D ni N/A)	Antes: N/A	*/
L=L+'		</th>																	';
L=L+'	<th><input disabled value="APAGAR" type="button" name="SWMAN'+N+'" id="SWMAN'+N+'" class="SWMAN" onClick="conmutar_estado('+N+');" />		';	/* CAPEAR v2.09.03+ //Lógica invertida */ 
L=L+'		</th>																	';
L=L+'	<th><select disabled name="RTCMD'+N+'" id="RTCMD'+N+'" onChange="seleccion_de_modos('+N+')" >							';
L=L+'		<option value="DESAC" selected>Desact.</option>												';
L=L+'		<option value="ONOFF">On/Off</option>													';
L=L+'		<option value="RESET">Reset</option>													';
L=L+'		</select>																';
L=L+'		</th>																	';
L=L+'	<th><input disabled value="'+HR_ONdef+'" type="text" 	name="HR_ON'+N+'" id="HR_ON'+N+'" maxlength="5" size="3" class="HR_HR" />		';
L=L+'		</th>																	';
L=L+'	<th><input disabled value="'+HR_OFdef+'" type="text" 	name="HR_OF'+N+'" id="HR_OF'+N+'" maxlength="5" size="3" class="HR_HR" />		';
L=L+'		</th>																	';
L=L+'	<th><input disabled value="'+RDLAYdef+'" type="text" 	name="RDLAY'+N+'" id="RDLAY'+N+'" maxlength="2" size="1" class="RDLAY" />		';
L=L+'		<span class="unidades">seg.</span>													';
L=L+'		</th>																	';
L=L+'	<th><input disabled type="checkbox" 			name="RAUTO'+N+'" id="RAUTO'+N+'" onClick="seleccion_de_modos('+N+')" />		';
L=L+'		</th>																	';
L=L+'	<th><input disabled value="'+IP___def+'" type="text"	name="IP___'+N+'" id="IP___'+N+'" maxlength="15" size="16" class="IP___" />		';
L=L+'		</th>																	';
L=L+'	<th><input disabled value="'+RPERIdef+'" type="text"	name="RPERI'+N+'" id="RPERI'+N+'" maxlength="2" size="1" class="RPERI" />		';
L=L+'		<span class="unidades">seg.</span>													';
L=L+'		</th>																	';
L=L+'	<th><span class="unidades">N<sub>f</sub> =</span>												';
L=L+'		<input disabled value="'+RTRIGdef+'" type="text" name="RTRIG'+N+'" id="RTRIG'+N+'" maxlength="1" size="1" class="RTRIG" />		';
L=L+'		</th>																	';
L=L+'	<th><iframe width="159" height="23" frameborder="0" scrolling="no" name="estado'+N+'" ></iframe>						';	// src="p'+N+'estado.shtml"
L=L+'		</th>																	';
L=L+'	</tr>																		';

	return L;
	}


function verifica_HORAS(N)	//N es el # de puerto
{
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda
	var RTCMD=document.getElementById('RTCMD'+N).value;
	var HR_ON=document.getElementById('HR_ON'+N).value;
	var HR_OF=document.getElementById('HR_OF'+N).value;
	/* HORA ON------------------------------------------- */
	//verifica valor
	vHR_ON=1;	//empiezo por suponer que está todo bien
	if (HR_ON.length!=5) vHR_ON=0;			//verifico longitud=5
	else if (HR_ON.substr(2,1)!=':') vHR_ON=0;	//verifico caracter separador ":"
	else {							//verifico que el input es numerico
		hh=HR_ON.substr(0,2); mm=HR_ON.substr(3,2);
		if ((isNaN(hh))||(isNaN(mm))) vHR_ON=0;
		else if((parseInt(hh)<0)||(parseInt(hh)>23)||(parseInt(mm)<0)||(parseInt(mm)>59)) vHR_ON=0;
		}
	//corrige si hubo error
	if (vHR_ON==0) {
		document.getElementById('HR_ON'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('HR_ON'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	/* HORA OF------------------------------------------- */
	//verifica valor
	vHR_OF=1;	//empiezo por suponer que está todo bien
	if (HR_OF.length!=5) vHR_OF=0;			//verifico longitud=5
	else if (HR_OF.substr(2,1)!=':') vHR_OF=0;	//verifico caracter separador ":"
	else {							//verifico que el input es numerico
		hh=HR_OF.substr(0,2); mm=HR_OF.substr(3,2);
		if ((isNaN(hh))||(isNaN(mm))) vHR_OF=0;
		else if((parseInt(hh)<0)||(parseInt(hh)>23)||(parseInt(mm)<0)||(parseInt(mm)>59)) vHR_OF=0;
		}
	//corrige si hubo error
	if (vHR_OF==0) {
		document.getElementById('HR_OF'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('HR_OF'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	/* HORAS IGUALES-------------------------------------- */
	//verifica valor
	vHR_ID=1;	//empiezo por suponer que está todo bien
	if((RTCMD=='ONOFF') && (HR_OF==HR_ON)) vHR_ID=0;
	//corrige si hubo error
	if (vHR_ID==0) {
		document.getElementById('HR_OF'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('HR_OF'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_RDLAY(N)	//N es el # de puerto
{
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda
	var RDLAY=document.getElementById('RDLAY'+N).value;
	//verifica valor
	vRDLAY=1;	//empiezo por suponer que está todo bien
	if ((isNaN(RDLAY))||(RDLAY=='')) vRDLAY=0;
		else if((parseInt(RDLAY)<RDLAYmin)||(parseInt(RDLAY)>RDLAYmax)) vRDLAY=0;
	//corrige si hubo error
	if (vRDLAY==0) {
		document.getElementById('RDLAY'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('RDLAY'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_IP___(N)	//N es el # de puerto
{
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda
	var IP___=document.getElementById('IP___'+N).value;
	//verifica valor
	vIP___=1;	//empiezo por suponer que está todo bien
	var X=0; 	//Var auxiliar temporal
	Xn=IP___.split('.');
	for (var i=0;i<4;i++) {
		X=parseInt(Xn[i]);	//Obtiene un entero si es que existe
		if (Xn[i]!=X+'')  	//Convierte X a cadena al sumarle la cadena nula
			vIP___=0;	//si no es 100% numerico entero, fracasa
		else if ((i<=3) && ((X<0) || (X>255)))
			vIP___=0;	//si es un numero negativo o mayor que 255, fracasa
		else if ((i==3) && ((X==0) || (X==255)))
			vIP___=0;	//si el ultimo octeto contiene una dirección broadcast o de red, fracasa
		}
	//corrige si hubo error
	if (vIP___==0) {
		document.getElementById('IP___'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('IP___'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_RPERI(N)	//N es el # de puerto
{
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda
	var RPERI=document.getElementById('RPERI'+N).value;
	//verifica valor
	vRPERI=1;	//empiezo por suponer que está todo bien
	if ((isNaN(RPERI))||(RPERI=='')) vRPERI=0;
		else if((parseInt(RPERI)<RPERImin)||(parseInt(RPERI)>RPERImax)) vRPERI=0;
	//corrige si hubo error
	if (vRPERI==0) {
		document.getElementById('RPERI'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('RPERI'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_RTRIG(N)	//N es el # de puerto
{
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda
	var RTRIG=document.getElementById('RTRIG'+N).value;
	//verifica valor
	vRTRIG=1;	//empiezo por suponer que está todo bien
	if ((isNaN(RTRIG))||(RTRIG=='')) vRTRIG=0;
		else if((parseInt(RTRIG)<RTRIGmin)||(parseInt(RTRIG)>RTRIGmax)) vRTRIG=0;
	//corrige si hubo error
	if (vRTRIG==0) {
		document.getElementById('RTRIG'+N).value='';		//se borra el valor mal ingresado
		document.getElementById('RTRIG'+N).focus();		//lo enfoco
		return 0;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_datos_ingresados(N,buchon)	//N es el # de puerto; buchon indica si alerta o no ante un fallo
{	
	if (!document.getElementById('ACTPT'+N).checked) return 1;//si el puerto esta desactivado me voy a la mierda

	/* Condicionantes: no se chequeará el elemento que esté desactivado */
	var VRTRST=(document.getElementById('RTCMD'+N).value=="RESET");	//RTC en modo RESET
	var VRTACT=(document.getElementById('RTCMD'+N).value!="DESAC");	//RTC en modo distinto de DESACT
	var VRAUTO=document.getElementById('RAUTO'+N).checked;		//AutoRST activado

	/* HORAS (todas)------------------------------------ */
	if (VRTACT && !verifica_HORAS(N)) {
		if (buchon) {
			var L='';
			L=L+'Error en alguna de las horas asignadas al puerto '+N+'.\nVerificar que se cumplen las condiciones siguientes:\n\n';
			L=L+'	1. Deben figurar 2 digitos numéricos para cada magnitud, separados por \' : \'.\n';
			L=L+'	2. La Hora ON no puede ser igual a la Hora OFF cuando el modo RTC es "On/Off".\n';
			L=L+'\n'+MSJ_VAL_VALIDO;
			alert(L);
			}
		return 0;
		}

	/* DURACION del RESET------------------------------- */
	if ((VRAUTO || VRTRST) && !verifica_RDLAY(N)) {
		if (buchon) {
			var L='';
			L=L+'Error en la duración de RST asignada al puerto '+N+'.\n\nDebe ser un valor numérico entre '+RDLAYmin+' y '+RDLAYmax+'.\n';
			L=L+'( Valor sugerido: '+RDLAYdef+' )\n';
			L=L+'\n'+MSJ_VAL_VALIDO;
			alert(L);
			}
		return 0;
		}

	/* IP ---------------------------------------------- */
	if (VRAUTO && !verifica_IP___(N)) {
		if (buchon) {
			var L='';
			L=L+'Establecer una dirección IP válida para el puerto '+N+'.';
			alert(L);
			}
		return 0;
		}

	/* PERIODO ENTRE PINGS-------------------------------- */
	if (VRAUTO && !verifica_RPERI(N)) {
		if (buchon) {
			var L='';
			L=L+'Error en el intervalo entre PINGs del puerto '+N+'.\n\nDebe ser un valor numérico entre '+RPERImin+' y '+RPERImax+'.\n';
			L=L+'( Valor sugerido: '+RPERIdef+' )\n';
			L=L+'\n'+MSJ_VAL_VALIDO;
			alert(L);
			}
		return 0;
		}

	/* UMBRAL DE FALLOS TOLERADOS------------------------- */
	if (VRAUTO && !verifica_RTRIG(N)) {
		if (buchon) {
			var L='';
			L=L+'Error en el umbral de fallos del puerto '+N+'.\n\nDebe ser un valor numérico entre '+RTRIGmin+' y '+RTRIGmax+'.\n';
			L=L+'( Valor sugerido: '+RTRIGdef+' )\n';
			L=L+'\n'+MSJ_VAL_VALIDO;
			alert(L);
			}
		return 0;
		}

	/*---------END-OF-VERIFICACIONES------------------------*/
	return 1;
	}


function autoriza_submit(sn)
{
	switch(sn) {
		case -1:
			document.getElementById('submit').style.display='none';
			break;
		case 0:
			document.getElementById('submit').value='CORREGIR LOS VALORES - Clic aqui para conocer el error';
			document.getElementById('submit').style.background='red';
			document.getElementById('submit').type='button';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').onclick=function() {verifica_datos_todos(1);};
			break;
		case 1:
			document.getElementById('submit').value='APLICAR';
			document.getElementById('submit').style.background='#33bb33';
			document.getElementById('submit').type='submit';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').onclick=function() {ping_check(4); autoriza_submit(-1);};
			break;
		}
	return;
	}

function pausa(ms) 
{
	ms += new Date().getTime();
	while (new Date() < ms){};
}

function ping_check(N)
{
	var rnd=Math.random();
	ping_on='p'+N+'ping_on.shtml?anticache='+rnd; //'; //
	ping_of='p'+N+'ping_of.shtml?anticache='+rnd; //'; //
	//pausa(1000); //impongo una pausa para dar tiempo a que las variables submitteadas se acomoden en la matriz
	if(document.getElementById('RAUTO'+N).checked) {
		window.open(ping_on,'estado5');
		}
	else {
		window.open(ping_of,'estado5');
		}
	return;
}
	
function verifica_datos_todos(buchon)
{
	var X=1; 			//variable auxiliar
	for(var i=PRT_pri;i<=PRT_ult;i++) {
		if (!verifica_datos_ingresados(i,buchon)) {
			autoriza_submit(0);
			return;
			}
		else X=(X & !document.getElementById('ACTPT'+i).checked);
		}
	if (X) autoriza_submit(-1); else autoriza_submit(1);
	return;
	}


function ayuda(AYUDIN)
{
	alert(AYUDIN);
	return;
	}


/*  *** Anulada porque el LPC no tolera imagenes muy pesadas. Se deja solo como referencia ***
function backgroundimage_roll()
{
	FONDO++; if (FONDO>2) FONDO=0;	//roll de fondos
	var BODY=document.getElementById('el_body');
	if (FONDO==0) {
		BODY.style.background='url("fondo0.gif") repeat fixed';
	} else {
		BODY.setAttribute('style','background:url("fondo'+FONDO+'.jpg") no-repeat fixed');  //para intentar: NO USAR LA FORMA ABREVIADA, SETEAR CADA ATTRIBUTO EN SITNAXIS COMPLETA Y VER Q PASA
		//BODY.setAttribute('style','background-size:100%');

		//BODY.background='url("fondo1.jpg") no-repeat fixed; background-size:100%;';
	 	//document.body.style.background='url("fondo1.jpg") no-repeat fixed; size="100%";'; //'+FONDO+'.jpg") no-repeat fixed;'; // background-size="100%";'
		}
	return;
	}

*/

