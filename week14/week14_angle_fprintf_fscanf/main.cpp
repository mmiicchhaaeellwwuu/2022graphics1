#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE*fout=NULL,*fin=NULL;
void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout,"%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout); fout=NULL;
    }
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();///請glut重畫畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///四邊形

    glPushMatrix();///右半部
    glTranslatef(0.3,0.4,0);///把手臂掛回身體
    glRotatef(angle[0],0,0,1);///旋轉，對z軸轉
    glTranslatef(-0.3,-0.4,0);///把手臂旋轉中心放在正中心
        glColor3f(1,0,0);///紅色
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛回身體
            glRotatef(angle[1],0,0,1);///旋轉，對z軸轉
            glTranslatef(-0.7,-0.4,0);///把手臂旋轉中心放在正中心
            glColor3f(0,1,0);///綠色
            glRectf(0.7,0.5,1.0,0.3);///下手肘
        glPopMatrix();
    glPopMatrix();


    glPushMatrix();///左半部
    glTranslatef(-0.3,0.4,0);///把手臂掛回身體
    glRotatef(angle[2],0,0,1);///旋轉，對z軸轉
    glTranslatef(0.3,-0.4,0);///把手臂旋轉中心放在正中心
        glColor3f(1,0,0);///紅色
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///把手臂掛回身體
            glRotatef(angle[3],0,0,1);///旋轉，對z軸轉
            glTranslatef(0.7,-0.4,0);///把手臂旋轉中心放在正中心
            glColor3f(0,1,0);///綠色
            glRectf(-0.7,0.5,-1.0,0.3);///下手肘
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week14 angle fprintf fscanf");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
