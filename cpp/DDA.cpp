#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include<gl/gl.h> 
#include<gl/glut.h>
#include<math.h>
using namespace std;
void init()
        { 
////        glutInit(&argc,argv);
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
        glClear(GL_COLOR_BUFFER_BIT);
        int swap_flag = 0;
        if (abs(x2-x1) < abs(y2-y1))
		{
////            x1, y1 = y1, x1;
			int t;
			t=x1; x1=y1; y1=t;
////            x2, y2 = y2, x2;
			t=x2; x2=y2; y2=t;	
            swap_flag = 1;
    	}
    	float x,y,dy;
		x = x1+0.5; y=y1 + 0.5;      
        dy = (y2-y1)/(x2-x1);
        glBegin(GL_POINTS);
        if (swap_flag)
        {
			    for(int i=0;i<(x2-x1);i++)
				{
                x=x+1; y =y+dy;               
                glVertex2d(int(y), int(x));
				}
		}
		else
		{
            for(int i=0;i<(x2-x1);i++)
				{
                x=x+1; y = y+dy;
                glVertex2d(int(x), int(y));
            	}
        glEnd();
        glFlush();
    	}
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


