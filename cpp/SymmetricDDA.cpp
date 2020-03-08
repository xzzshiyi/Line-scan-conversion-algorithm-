#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include<gl/gl.h> 
#include<gl/glut.h>
#include<math.h>
using namespace std;
void init()
        { 
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(200, 200);
        glutCreateWindow("line");
		}
		
		
		
    void end_init()
		{
        glClearColor(1.0, 1.0, 1.0, 0);
        glColor3f(0, 0, 0);
        gluOrtho2D(0.0, 500.0, 0.0, 500.0);
        glutMainLoop();
		}
		
		
		


    void display()
	{
		int x1=0;int y1=0;int x2=180;int y2=180;
		float dx,dy;
		dx = x2-x1;
        dy = y2-y1;
        int max_increment = (dx>dy)?dx:dy;
        int n = 0;float N;
        while (1)
		{
            max_increment = max_increment >> 1;
            n ++;
            if (max_increment < 1) break;
        	N = pow(2,n);
		}
		float x_increment = dx/N;
        float y_increment = dy/N;
        glBegin(GL_POINTS);
        glVertex2d(int(x1), int(y1));
        float x,y; x = x1; y= y1;
        for (int i=0;i<N;i++)
				{
                x  = x + x_increment;  y= y + y_increment;
                glVertex2d(int(x), int(y));
                }
        glEnd();
        glFlush();

	}
    	
    void run()
	    {
        glutDisplayFunc(display);
        end_init();
		}

int main(int argc, char** argv)

{
    glutInit(&argc, argv);
	init();
	run();
	end_init();
	return 0;
}


