from BaseClass import *



'''
Bresenham算法
'''


class BresenhamLine(Line):
    def __init__(self, x1, y1, x2, y2,name):
        super(BresenhamLine,self).__init__(x1, y1, x2, y2,name)

    def display(self):
        dx = abs(self.x2 - self.x1)
        dy = self.y2 - self.y1
        k_value = 1 if dy > 1 else -1
        dy = abs(dy)
        glClear(GL_COLOR_BUFFER_BIT)
        x1, y1, x2, y2 = self.x1, self.y1, self.x2, self.y2
        swap_flag = 0           # 用检测x,y是否需要互换
        if dx < dy:               # 若斜率大于1则互换
            x1, y1 = y1, x1
            x2, y2 = y2, x2
            dx, dy = dy, dx
            swap_flag = 1
        d = 2*dx - dy           # 生成d1
        increment1, increment2 = 2*dy, 2*(dy-dx)   # di<0 和di>0 时候的增量
        x0, y0 = x1, y1
        glBegin(GL_POINTS)                      # 开始绘制
        if swap_flag:                           # 在x,y呼唤情况下 （如果这个判断放在while里面代码量会变小，但开销会变大）
            while x0 < x2:
                x0 += 1
                if d < 0:
                    d += increment1
                else:
                    y0 += 1
                    d += increment2
                glVertex2d(y0,x0)            # 把x,y再换回来
        else:                              # 没换，直接绘制
            while x0 < x2:
                x0 += 1
                if d < 0:
                    d += increment1
                else:
                    y0 += k_value
                    d += increment2
                glVertex2d(x0,y0)
        glEnd()
        glFlush()

if __name__ == '__main__':
    line = BresenhamLine(0,0,3800,180,'Bresenham.py')
    line.run()