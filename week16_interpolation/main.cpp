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
        printf("%.1f ",angle[i]);///�p�¦L�X��
        fprintf(fout,"%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout); fout=NULL;
    }
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        OldAngle[i]=NewAngle[i];
        fscanf(fin,"%f",&NewAngle[i]);
    }
    glutPostRedisplay();///���e�e��
}
void myInterpolate(float alpha)
{
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*NewAngle[i]+(1-alpha)*OldAngle[i];
    }
}
void timer(int t)
{
    if(t%50==0) myRead();
    myInterpolate((t%50)/50.0);
    glutPostRedisplay();
    glutTimerFunc(20,timer,t+1);
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='p')///play
    {
        myRead();
        glutTimerFunc(0,timer,0);
    }
    if(key=='s') myWrite();///�զn�ʧ@,�~save�s��
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
    //myWrite();
    oldX=x;
    glutPostRedisplay();///��glut���e�e��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ�
    glRectf(0.3,0.5,-0.3,-0.5);///�|���

    glPushMatrix();///�k�b��
    glTranslatef(0.3,0.4,0);///����u���^����
    glRotatef(angle[0],0,0,1);///����A��z�b��
    glTranslatef(-0.3,-0.4,0);///����u���त�ߩ�b������
        glColor3f(1,0,0);///����
        glRectf(0.3,0.5,0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///����u���^����
            glRotatef(angle[1],0,0,1);///����A��z�b��
            glTranslatef(-0.7,-0.4,0);///����u���त�ߩ�b������
            glColor3f(0,1,0);///���
            glRectf(0.7,0.5,1.0,0.3);///�U��y
        glPopMatrix();
    glPopMatrix();


    glPushMatrix();///���b��
    glTranslatef(-0.3,0.4,0);///����u���^����
    glRotatef(angle[2],0,0,1);///����A��z�b��
    glTranslatef(0.3,-0.4,0);///����u���त�ߩ�b������
        glColor3f(1,0,0);///����
        glRectf(-0.3,0.5,-0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///����u���^����
            glRotatef(angle[3],0,0,1);///����A��z�b��
            glTranslatef(0.7,-0.4,0);///����u���त�ߩ�b������
            glColor3f(0,1,0);///���
            glRectf(-0.7,0.5,-1.0,0.3);///�U��y
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week15 angle TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
