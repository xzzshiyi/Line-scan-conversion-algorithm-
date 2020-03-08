from OpenGL.GLU import *
from OpenGL.GLUT import *
from OpenGL.GL import *
'''
@author 相珍正
@desc 本模块是生成图形的基础类
@date 2020/03/07
'''
class Line():

    '''__init__ 需要传入x1 y1 x2 y2
       display 方法用来重写生成直线
    '''
    def __init__(self,x1,y1,x2,y2,name):
        glutInit()
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
        glutInitWindowSize(800, 600)
        glutInitWindowPosition(200, 200)
        glutCreateWindow(name)
        self.x1, self.y1, self.x2, self.y2 = x1, y1, x2, y2

    def end_init(self):
        glClearColor(1.0, 1.0, 1.0, 0)
        glColor3f(0, 0, 0)
        gluOrtho2D(0.0, 500.0, 0.0, 500.0)
        glutMainLoop()

    def display(self):
        pass
    def run(self):
        glutDisplayFunc(self.display)
        self.end_init()
