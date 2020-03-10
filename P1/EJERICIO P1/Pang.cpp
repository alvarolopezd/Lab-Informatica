#include "glut.h"
#include <math.h>


typedef struct
{
	float x=0, y=10, z=20;
}vista;
vista camara;

typedef struct
{
	float posX = 0;
	float posY = 0;
	float posZ = 0;
}octaedro;
octaedro o;

typedef struct
{
	float radioInt=2;
	float radioExt=4;
	float sides = 50;
	float rings = 100;

}toroide;
toroide t;

typedef struct
{
	float radius;
	float slices;
	float stacks;
	float posX;
	float posY;
	float posZ;
}esfera;
esfera e1 = { 2,10, 10, -7,3,0 };
esfera e2 = { 2,10, 10, 14,0,0 };
esfera e3 = { 2,10, 10, 0,-6,0 };
esfera e4 = { 2,10, 10, -14,0,0 };

typedef struct // Empieza en blanco
{
	int colorX=255;
	int colorY=255;
	int colorZ=255;

}colores;
colores color;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);	


unsigned char colorRojoCubo = 255; //Creo que esto se pone para que el color no supere el numero 255
unsigned char colorVerdeCubo = 255; 
unsigned char colorAzulCubo = 255;

int main(int argc,char* argv[])
{

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Figuritas_P1_T2"); ///NOMBRE EL NOMBRE DEL JUEGO

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
	gluLookAt(camara.x, camara.y, camara.z,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	///////////////////////////    LAS POSICIONES SON RELATIVAS!!!!!
	
// ESFERAS
	glColor3ub(color.colorX, color.colorY, color.colorZ); 
	
	glTranslatef(e1.posX, e1.posY, e1.posZ); 
	glutWireSphere(e1.radius, e1.slices,e1.stacks);
	
	glTranslatef(e2.posX, e2.posY, e2.posZ);
	glutWireSphere(e2.radius, e2.slices, e2.stacks);
	
	glTranslatef(e3.posX, e3.posY, e3.posZ);
	glutWireSphere(e3.radius, e3.slices, e3.stacks);
	
	glTranslatef(e4.posX, e4.posY, e4.posZ);
	glutWireSphere(e4.radius, e4.slices, e4.stacks);
	// TOROIDE
	glTranslatef(7, 3, 0);
	glColor3ub(0, 0, 255);
	glutWireTorus(t.radioInt, t.radioExt, t.sides,t.rings);
	// OCTAEDRO
	glColor3ub(255, 255, 0);  // AMARILLO
	glTranslatef(o.posX,o.posY, o.posZ);    // POSICION
	glutSolidOctahedron();



	
	

	//no borrar esta linea ni poner nada despues
	///Para limpieza de buffers 
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	// MOVIMIENTO CUBO
	if (key == 'w')
		o.posY += 0.25;
	if (key == 's')
		o.posY -= 0.25;
	if (key == 'd')
		o.posX += 0.25;
	if (key == 'a')
		o.posX -= 0.25;
	if (key == '1') // Rojo
	{
		color.colorX = 255;
		color.colorY = 0;
		color.colorZ = 0;
	}
	if (key == '2') // Verde
	{
		color.colorX = 0;
		color.colorY = 255;
		color.colorZ = 0;
	}
	if (key == '3') // Azul
	{
		color.colorX = 0;
		color.colorY = 0;
		color.colorZ = 255;
	}

	if (key == '+')
	{
		e1.radius += 0.25;
		e2.radius += 0.25;
		e3.radius += 0.25;
		e4.radius += 0.25;
	}

	if (key == '-')
	{
		e1.radius -= 0.25;
		e2.radius -= 0.25;
		e3.radius -= 0.25;
		e4.radius -= 0.25;
	}
	
	if (key == '4')
	{
		camara.x -= 2;
	}
	if (key == '6')
	{
		camara.x += 2;
	}
	if (key == '7')
	{
		camara.z -= 2;
	}
	if (key == '9')
	{
		camara.z += 2;
	}


	/*if (key == '7' && color.colorX >= 0 && color.colorX <= 255)
		color.colorX = color.colorX + 50;
	if (key == '4' && color.colorX >= 0 && color.colorX <= 255)
		color.colorX = color.colorX - 50;
	if (key == '8' && color.colorY >= 0 && color.colorY <= 255)
		color.colorY = color.colorY + 50;
	if (key == '5' && color.colorY >= 0 && color.colorY <= 255)
		color.colorY = color.colorY - 50;
	if (key == '9' && color.colorZ >= 0 && color.colorZ <= 255)
		color.colorZ = color.colorZ + 50;
	if (key == '6' && color.colorZ >= 0 && color.colorZ <= 255)
		color.colorZ = color.colorZ - 50;*/
	   	  


	// Esta linea no se borra, hace que cuando le de a algo del tecladome ejecute de nuevo el void main,
	// pero con el cambio efectuado tras el evento del teclado en la variable cambiada
	glutPostRedisplay();
}

void OnTimer(int value) /// Efectua el main con los cambios que haya dentro del OnTimer 
{
	t.radioExt += 0.1;
	if (t.radioExt > 6)
		t.radioExt = 4;
	

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

