from BaseClass import *


class SymmetricDDA(Line):
    def __init__(self,x1, y1, x2, y2,name):
        super(SymmetricDDA, self).__init__(x1, y1, x2, y2 ,name)

    def build_N(self):
        # 生成一个合理N 用来分隔线段 通过移位操作就可以实现
        self.dx = self.x2-self.x1
        self.dy = self.y2-self.y1
        max_increment = max(self.dx,self.dy)
        n = 0
        while 1:
            max_increment = max_increment >> 1
            n += 1
            if max_increment < 1:
                break
        self.N = 2**n

    def display(self):
        self.build_N()
        x_increment = self.dx/self.N
        y_increment = self.dy/self.N
        glBegin(GL_POINTS)
        glVertex2d(int(self.x1), int(self.y1))
        x,y = self.x1, self.y1
        for i in range(self.N):
                x, y = x + x_increment, y + y_increment
                glVertex2d(int(x), int(y))
        glEnd()
        glFlush()

if __name__ == '__main__':
    line = SymmetricDDA(0,0, 280, 480, 'SymmetricDDA.py')
    line.run()