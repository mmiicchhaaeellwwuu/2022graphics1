#include<GL/glut.h>
#include<opencv/highgui.h>
void myTexture()
{
    IplImage * img=cvLoadImage("�_���D���c.jpg");
    cvShowImage("opencv",img);
    cvWaitKey(0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week09_texture");
    glutDisplayFunc(display);
    glutMainLoop();
}
