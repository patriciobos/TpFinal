


/*
========================================================

**** PROYECTO CAPEAR - Programas "browser-side" Config *

========================================================
*/


/* VARIABLES GLOBALES */






//valores por defecto y cotas
var IPAdef=''; //192.168.0.200';
var MSKdef=''; //255.255.255.0';
var DGWdef=''; //192.168.0.100';













//variables de validación
var todo_ok=false;




//Mensajes
var MSJ_VAL_VALIDO='Por favor, ingresar un valor válido.';




















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
L=L+'	<input type="button" name="LISTO" id="submit" onMouseEnter="verifica_datos_todos(0);" />'; // onMouseEnter="verifica_datos_ingresados(1); verifica_datos_todos(0);" />';	//verifica_datos_ingresados(1); verifica_datos_todos(0); verifica_PASWD();
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

function habilitar_cambios()
{
	var VHRCHG=document.getElementById('HRCHG').checked;
	var VIPCHG=document.getElementById('IPCHG').checked;
	var VPWCHG=document.getElementById('PWCHG').checked;
	var VFWCHG=document.getElementById('FWCHG').checked;
	if (VHRCHG || VIPCHG || VPWCHG || VFWCHG) {
		document.getElementById('PWD').disabled=false;
		autoriza_submit(1);
		} else {
		document.getElementById('PWD').disabled=true;
		autoriza_submit(-1);
		}
	if(VHRCHG) {	//habilito
		document.getElementById('HRS').disabled=false;		
		document.getElementById('HRS').value=time_hhmm();
		} else {	//deshabilito
		document.getElementById('HRS').disabled=true;
		document.getElementById('HRS').value='';
		}
	if (VIPCHG) {	//habilito
		document.getElementById('IPA').disabled=false;		
		document.getElementById('MSK').disabled=false;		
		document.getElementById('DGW').disabled=false;		
		} else {	//deshabilito
		document.getElementById('IPA').disabled=true;		
		document.getElementById('MSK').disabled=true;		
		document.getElementById('DGW').disabled=true;		
		}
	if(VPWCHG) {	//habilito
		document.getElementById('NP1').disabled=false;		
		document.getElementById('NP2').disabled=false;		
		} else {	//deshabilito
		document.getElementById('NP1').disabled=true;		
		document.getElementById('NP2').disabled=true;		
		}
	if(VFWCHG) {	//habilito
		document.getElementById('puer2fw').style.background='white';		
		} else {	//deshabilito
		document.getElementById('puer2fw').style.background='#b8b8b1';		
		}
	return;
	}	

function time_hhmm()		//antes:	time_hhmm(id)
{
	date = new Date;
    h = date.getHours();
    if(h<10) h = "0"+h;
    m = date.getMinutes();
    if(m<10) m = "0"+m;
	hhmm=h+':'+m;			//antes:	document.getElementById(id).value = hhmm;	// valido para ser llamada desde el HTML
	return hhmm+'';
    }
	
function listar_configs()
{
	var L='';

L=L+'	<tr id="hiddentr"><th colspan="3"><input type="hidden" id="PWDhidden" value=""  name="PASWD9" /></th></tr> ';	// linea invisible porque necesito que la PWD se transmita en 1er lugar
L=L+'	<tr><th	class="item"> Hora del dispositivo	</th><th class="invisible" rowspan="1">	<input type="checkbox"	id="HRCHG" 	onChange="habilitar_cambios();" />	</th>	';
L=L+'		<th><input disabled type="text" 		value=""	name="HORAS9" 	id="HRS" 	class="inputconfig" maxlength="5" /></th></tr>	';	// value="'+HRSdef+'"
L=L+'	<tr><th	class="item"> Dirección IP	</th><th class="invisible" rowspan="3">			<input type="checkbox"	id="IPCHG" 	onChange="habilitar_cambios();" />	</th>	';
L=L+'		<th><input disabled type="text" 		value="" 	name="IP___9" 	id="IPA" 	class="inputconfig" maxlength="15" /></th></tr>	';	// value="'+IPAdef+'"
L=L+'	<tr><th class="item"> Mascara de subred		</th>';
L=L+'		<th><input disabled type="text" 		value="" 	name="RPERI9" 	id="MSK" 	class="inputconfig" maxlength="15" /></th></tr>	';	// value="'+MSKdef+'"
L=L+'	<tr><th class="item"> Puerta de enlace		</th>';
L=L+'		<th><input disabled type="text" 		value="" 	name="RTRIG9" 	id="DGW" 	class="inputconfig" maxlength="15" /></th></tr>	';	// value="'+DGWdef+'"
L=L+'	<tr><th class="item"> Cambiar la contraseña por	</th><th class="invisible" rowspan="2">	<input type="checkbox" 	id="PWCHG"  onChange="habilitar_cambios();" />	</th>	';
L=L+'		<th><input disabled type="password" 	value="" 	name="RAUTO9" 	id="NP1"	class="inputconfig" maxlength="15" /></th></tr>	';
L=L+'	<tr id="NWPTR"><th class="item" style="font-size:0.75pc;"> Confirmar contraseña nueva</th>';
L=L+'		<th><input disabled type="password" 	value=""					id="NP2"	class="inputconfig" maxlength="15" /></th></tr>	';
L=L+'	<tr><th class="item"> Puertos AC &#8212;> Flash RAM </th><th class="invisible" rowspan="1">	<input type="checkbox"	id="FWCHG" name="FWCHG9" onChange="habilitar_cambios();" />';
L=L+'		<th id="puer2fw">Incrusta la configuración de puertos del Panel de Control <br /> en la memoria permanente (flash-RAM) del dispositivo.</th></tr>	';
L=L+'	<tr><th class="item" colspan="2" style="text-align:center; padding-left:10px; padding-right:0px;"> Contraseña actual	</th>';
L=L+'		<th><input disabled type="password" 	value=""				 	id="PWD"	class="inputconfig" maxlength="15" /></th></tr>	';	//	sin "name", se traslada a id="trhidden"

/*
L=L+'	<!--Puerto# '+N+' -->																		';
L=L+'																								';
L=L+'	<tr class="puerto" onChange="verifica_datos_ingresados('+N+'); verifica_datos_todos(0);" >	';
L=L+'																								';
*/
	return L;
	}


function verifica_HORAS()
{
	if (!document.getElementById('HRCHG').checked) return 1;	//todo bien, further checks not needed (FCNN)
	var HORAS=document.getElementById('HRS').value;

	//verifica valor
	vHORAS=1;	//empiezo por suponer que está todo bien
	if (HORAS.length!=5) vHORAS=0;			//verifico longitud=5
	else if (HORAS.substr(2,1)!=':') vHORAS=0;	//verifico caracter separador ":"
	else {							//verifico que el input es numerico
		hh=HORAS.substr(0,2); mm=HORAS.substr(3,2);
		if ((isNaN(hh))||(isNaN(mm))) vHORAS=0;
		else if((parseInt(hh)<0)||(parseInt(hh)>23)||(parseInt(mm)<0)||(parseInt(mm)>59)) vHORAS=0;
		}
	//corrige si hubo error
	if (vHORAS==0) {
		document.getElementById('HRS').value='';		//se borra el valor mal ingresado
		document.getElementById('HRS').focus();		//lo enfoco
		return 0;	//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}

	
function verifica_IP___(id)	//ID es la identificación del input a revisar
{
	if(!document.getElementById('IPCHG').checked) return 1;	//todo bien, further checks not needed (FCNN)
	if (document.getElementById(id).value=='') return 0;	//si está vacío está mal, FCNN.
	var IP___=document.getElementById(id).value;
	//verifica valor
	var vIP___=1;	//empiezo por suponer que está todo bien
	var X=0; 		//Var auxiliar temporal
	Xn=IP___.split('.');
	for (var i=0;i<4;i++) {
		X=parseInt(Xn[i]);	//Obtiene un entero si es que existe
		if (Xn[i]!=X+'')   	//Convierte X a cadena al sumarle una cadena (nula)
			vIP___=0;		//si no es 100% numerico entero, fracasa
		else if ((i<=3) && (((X+0)<0) || ((X+0)>255))) //Convierte X a numerico al sumarle un numero (nulo)
			vIP___=0;		//si es un numero negativo o mayor que 255, fracasa
		else if ((id!='MSK') && (i==3) && (((X+0)==0) || ((X+0)==255))) //Convierte X a numerico al sumarle un numero (nulo)
			vIP___=0;		//si el ultimo octeto contiene una dirección broadcast o de red, fracasa (MASCARA exceptuado)
		}
	//corrige si hubo error
	if (vIP___==0) {
		document.getElementById(id).value='';		//se borra el valor mal ingresado
		document.getElementById(id).focus();		//lo enfoco
		return 0;					//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	return 1;
	}


function verifica_NPASWD()
{
	if(!document.getElementById('PWCHG').checked) return 1;	//todo bien, further checks not needed (FCNN)

	var NP1=document.getElementById('NP1').value;
	var NP2=document.getElementById('NP2').value;

	/* PASSWORDS "NUEVAS" DEBEN SER IGUALES------------------ */
	if (NP1!=NP2) {
		document.getElementById('NP1').focus();		//lo enfoco
		return -1;						//me voy: 1 dato malo hay que corregirlo, no tiene sentido seguir con otros
		}
	else if (NP1.length==0) {
		document.getElementById('NP1').focus();		//lo enfoco
		return 0;
		}
	return 1;
	}


function verifica_CPASWD()
{
	var VHRCHG=document.getElementById('HRCHG').checked;
	var VIPCHG=document.getElementById('IPCHG').checked;
	var VPWCHG=document.getElementById('PWCHG').checked;
	var VFWCHG=document.getElementById('FWCHG').checked;

	if (!VHRCHG && !VIPCHG && !VPWCHG & !VFWCHG) return 1;		//todo bien, further checks not needed (FCNN)
	
	var PWD=document.getElementById('PWD').value;

	/* PASSWORD ACTUAL DEBE ESTAR INGRESADA------------------ */
	if (PWD.length==0) {
		document.getElementById('PWD').focus();	//lo enfoco
		return 0;			//me voy: dato malo y hay que corregirlo sí o sí
		}
	return 1;
	}

	
function verifica_datos_ingresados(buchon)	//buchon indica si alerta o no ante un fallo
{	

	/* HORAS ------------------------------------------- */
	if (!verifica_HORAS()) {
		if (buchon) {
			var L='';
			L=L+'Establecer una hora correcta en el formato "HH:mm".';
			alert(L);
			}
		return 0;
		}

	/* IP ---------------------------------------------- */
	if (!verifica_IP___('IPA')) {
		if (buchon) {
			var L='';
			L=L+'Establecer una dirección IP válida.';
			alert(L);
			}
		return 0;
		}

	/* MASCARA ----------------------------------------- */
	if (!verifica_IP___('MSK')) {
		if (buchon) {
			var L='';
			L=L+'Establecer una mascara de subred válida.';
			alert(L);
			}
		return 0;
		}

	/* PUERTA DE ENLACE -------------------------------- */
	if (!verifica_IP___('DGW')) {
		if (buchon) {
			var L='';
			L=L+'Establecer una puerta de enlace válida.';
			alert(L);
			}
		return 0;
		}

	/* NEW PASSWORD ------------------------------------ */
	switch(verifica_NPASWD()) {
		case 0:
			if (buchon) {
				var L='';
				L=L+'No se permite escoger una contraseña vacía.';
				alert(L);
				}
			return 0;
			break;
		case -1:
			if (buchon) {
				var L='';
				L=L+'Las contraseñas nuevas no coinciden.\n';
				L=L+'  Por favor ingréselas nuevamente.';
				alert(L);
				/*Lo que sigue es una excepción necesaria a toda la función de verificar */
				document.getElementById('NP1').value='';	//se borra el valor no coincidente
				document.getElementById('NP2').value='';	//se borra el valor no coincidente
				}
			return 0;
			break;
		default:
		}

	/* PASSWORD ACTUAL OBLIGATORIA ---------------------- */
	if (!verifica_CPASWD()) {
		if (buchon) {
			var L='';
			L=L+' Es requisito conocer la contraseña actual \n';
			L=L+'para introducir cambios en la configuración.';
			alert(L);
			}
		return 0;
		}
	
	/*---------END-OF-VERIFICACIONES----------------------*/
	return 1;
	}


function autoriza_submit(sn)
{
	switch(sn) {
		case -1:
			document.getElementById('submit').style.display='none';
			break;
		case 0:
			document.getElementById('submit').value='CORREGIR LOS VALORES - Clic aqui para ayuda';
			document.getElementById('submit').style.background='red';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').type='button';	//anti-hack: esto ANTES que function
			document.getElementById('submit').onclick=function() {verifica_datos_todos(1);};
			document.getElementById('PWDhidden').value='';	//*NEW*
			break;
		case 1:
			document.getElementById('submit').value='APLICAR';
			document.getElementById('submit').style.background='#33bb33';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').onclick=function() {verifica_datos_todos(1);};
			//se traslada el valor de password a otro input para que figure como primer variable en el envio GET 
			document.getElementById('PWDhidden').value=document.getElementById('PWD').value;	//*NEW* 
			document.getElementById('submit').type='submit';	//anti-hack: esto DESPUES que function
			break;
		}
	return;
	}


function verifica_datos_todos(buchon)
{

		if (!verifica_datos_ingresados(buchon)) {
			autoriza_submit(0);
			return;
			}

	autoriza_submit(1);
	return;
	}
