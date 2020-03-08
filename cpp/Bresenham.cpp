#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include<gl/gl.h> 
#include<gl/glut.h>
#include<math.h>
using namespace std;
void init()
        { 
//        glutInit(&argc,argv);
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
	    int x1=0;int y1=0;int x2=380;int y2=180;
      	int dx = abs(x2 - x1);
        int dy = y2 - y1;
        int k_value = dy > 0? 1:-1;
        dy = abs(dy);
        glClear(GL_COLOR_BUFFER_BIT);
        int swap_flag = 0 ;          
        if (dx < dy)
		{              
			int t;
			t=x1; x1=y1; y1=t;
			t=x2; x2=y2; y2=t;	
            swap_flag = 1;
            t=dx; dx=dy;dy=t;
            swap_flag = 1;
    	}
        int d = 2*dx - dy;          
        int increment1= 2*dy;int increment2 = 2*(dy-dx);
        int x0 = x1;int y0 =y1;
        glBegin(GL_POINTS);                      
        if (swap_flag)
		{            
            while (x0 < x2)
                x0 ++;
                if (d < 0) d =d+increment1;
                else{	
            		y0 ++;
                    d =d+increment2;
            		}
				glVertex2d(y0,x0);
		}
        else
		{                            
            while (x0 < x2)
			{
                x0 += 1;
                if (d < 0) d += increment1;
                else{
                    y0 += k_value;
                    d += increment2;
                	}
				glVertex2d(x0,y0);
			}
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
