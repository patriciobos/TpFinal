


/*
========================================================

**** PROYECTO CAPEAR - Programas "browser-side" EntryG *

========================================================
*/


/* VARIABLES GLOBALES */

ENTRYGATEPASSWORD='CAPEAR';

















































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

	
function runScript(e) {
    if (e.keyCode == 13) {
        var tb = document.getElementById("pwd_box");
        eval(tb.value);
        return false;
    }
}


function password_box()
{	
	var L='';
L=L+'	<h1 id="pwd_box"><input type="password" 	value="" 	name="PASWD9" 	id="PWD1"	class="inputconfig" maxlength="15" onChange="verifica_datos_todos(0);" onMouseMove="verifica_datos_todos(0);" onkeypress="return runScript(event)" /></h1>';

	return L;
	}	


function autoriza_submit(sn)
{
	switch(sn) {
		case -1:
			document.getElementById('submit').style.display='none';
			break;
		case 0:
			document.getElementById('submit').value='Escribir la contraseña';
			document.getElementById('submit').style.background='red';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').type='button';	//anti-hack: esto ANTES que function
			document.getElementById('submit').onclick=function() {verifica_datos_todos(0);};
			break;
		case 1:
			document.getElementById('submit').value='ENTRAR';
			document.getElementById('submit').style.background='#33bb33';
			document.getElementById('submit').style.display='inline';
			document.getElementById('submit').onclick=function() {verifica_datos_todos(0);};
			/* document.getElementById('submit').type='submit';	//anti-hack: esto DESPUES que function */
			PASSWORD=document.getElementById('PWD1').value;
			if (PASSWORD==ENTRYGATEPASSWORD) document.getElementById('submit').type='submit'
			else document.getElementById('submit').onclick=function() {alert('La contraseña ingresada no es valida');};
			break;
		}
	return;
	}


function verifica_datos_todos(buchon)
{
	var PASSWORD=document.getElementById('PWD1').value;
		if (!PASSWORD.length) {
			autoriza_submit(0);
			return;
			}

	autoriza_submit(1);
	return;
	}
