#include <math.h>
#include "mundo.h"
#include "octaedro.h"
#include "toroide.h"
#include "glut.h"
#include "esfera.h"

// Creo objeto m que pertenece a la clase mundo
Mundo m;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);	

/*unsigned char colorRojoCubo = 255; //Creo que esto se pone para que el color no supere el numero 255
unsigned char colorVerdeCubo = 255;
unsigned char colorAzulCubo = 255;*/

int main(int argc,char* argv[])
{

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MUNDO ALVARO"); ///NOMBRE EL NOMBRE DEL JUEGO

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks, se programan y van en funcion de los eventos, cuando ocurre un evento, el compilador se pone a ejecutar una funcion
	glutDisplayFunc(OnDraw); /// Se encara de pintar los objetos en la pantalla, se le pasa como parametro una funcion para hacer el dibujo
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer() /// Hacer que el objeto se mueva cada 25 ms
	glutKeyboardFunc(OnKeyboardDown); ///Detecta el teclado
	
	//Inicializo mundo
	m.InicioMundo(0, 10, 30);
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}
void OnDraw(void) /// Funcion para dibujar
{
	//Borrado de la pantalla àra evitar que haya otras cosas en la pantalla 
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	

	/// Cambiar el punto de vista, para saber de donde quieres ver el juego
	m.LookAt();	
	

	// Pintar mundo
	m.PintarMundo();
	

	//no borrar esta linea ni poner nada despues
	///Para limpieza de buffers 
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Declaro todas las acciones que se llevan a cabo en mi mundo
	m.AccionesMundo(key);
	   	 	
	// Esta linea no se borra, hace que cuando le de a algo del tecladome ejecute de nuevo el void main,
	// pero con el cambio efectuado tras el evento del teclado en la variable cambiada
	glutPostRedisplay();
}

void OnTimer(int value) /// Efectua el main con los cambios que haya dentro del OnTimer 
{
	//Defino las acciones en mi mundo que tienen en cuenta el tiempo
	m.MuevePorTiempo();
	

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}



