#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺身體

    glPushMatrix();///右手
        glTranslatef(0.2,0,0);///掛右邊
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.2,0,0);///把旋轉中心，放到世界中心
        glColor3f(1,0,0);///紅色
        glutSolidTeapot(0.2);
        glPushMatrix();
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左手
        glTranslatef(-0.2,0,0);///掛左邊
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(-0.2,0,0);///把旋轉中心，放到世界中心
        glColor3f(1,0,0);///紅色
        glutSolidTeapot(0.2);
        glPushMatrix();
            glTranslatef(-0.2,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
