

from BaseClass import *


class DDALines(Line):
    def __init__(self,x1,y1,x2,y2,name):
        super(DDALines, self).__init__(x1, y1, x2, y2, name)

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT)
        x1, y1, x2, y2 = self.x1, self.y1, self.x2, self.y2
        swap_flag = 0
        if abs(x2-x1) < abs(y2-y1):
            x1, y1 = y1, x1
            x2, y2 = y2, x2
            swap_flag = 1
        x, y = x1+0.5, y1 + 0.5      # 使误差在正负0.5之间
        dy = (y2-y1)/(x2-x1)
        glBegin(GL_POINTS)
        if swap_flag:
            for i in range(x2-x1):
                x, y = x+1, y+dy                # 每一段x+1，y加一个增量
                glVertex2d(int(y), int(x))
        else:
            for i in range(x2-x1):
                x, y = x+1, y+dy
                glVertex2d(int(x), int(y))
        glEnd()
        glFlush()


if __name__ == '__main__':
    Line = DDALines(20,15,530,330,'DDALine')
    Line.run()