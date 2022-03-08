# 2022graphics1
#week01
```
##第一個OpenGL程式
0. CodeBlocks 17.12 mingw 裝好
1. File-New-Project，選OpenGL專案
2. 在[...]的目錄，選「桌面」，week 01_OPENGL





3.下一步下一步，完成後，齒輪播放
4.會有彩色三角型旋轉
\Desktop\freeglut



##第一個 GLUT 專案
1.moodle下載 freeglut ... zip
2.解壓縮 桌面 freeglut目錄
3.桌面>freeglut>lib的libfreeglut.a將其複製並改成libglut32.a
4.CodeBlocks：File-New-Project，選GLUT
5.取名week01_GLUT
6.設定GLUT目錄 C:\Users\        \Desktop\freeglut





7.齒輪播放後有6個紅東西再轉   




 
##3.git
開啟 Git Bash
cd desktop 進入桌面
git clone https://你的網址
cd 2022graphics1 
git status 看狀態(紅色2個目錄)
git add . 把它加進去
git status 再看狀態(變綠色)
git config --global user.email 
git config --global user.name 
git commit -m "訊息"
git push 推送上雲端
(Chrome 要登入才行)
```
#week02
```##step01-1 跑範例
1.下載範例 http://jsyeh.org/3dcg10     data.zip   windows.zip   glut32.dll
2.window.zip  解壓  下載\windows\Shapes.exe
   data.zip  解壓  下載\windows\data\模型
   glut32.dll  複製  下載\windows\glut32.dll
3.跑Shapes.exe
   右鍵點左半部：大頂點、顏色
   右鍵點右半部：point~polygon





##step01-2 跑上週程式
1.安裝git for windows
2.git bash：cd desktop，git clone 網址 cd 2022graphicsl
3.安裝freeglut，改檔名lib\libglut32.a 
4.codeblocks file-open week01_GLUT


```
##step02-1 寫程式
```c++
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第二週的程式哦!");
    glutDisplayFunc(display);
    glutMainLoop();
}


```
##step03-1 寫程式
```c++
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);

    glBegin(GL_POLYGON);
        glColor3f(1,0,1);
        glVertex2f(-1,-1);

        glColor3f(1,0,0);
        glVertex2f(+1,-1);

        glColor3f(1,1,0);
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第二週的程式哦!");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

#week03
```
##step01：

1.下載範例 http://jsyeh.org/3dcg10     data.zip   windows.zip

   windows.zip >下載\windows\Transformation.exe

   data.zip >下載\windows\data\模型.obj

2.執行Transformation.exe

   (右上)右鍵：換模型

   (下方)拖曳綠色數值
```
3.上週程式
```c++
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);

    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

##step02：

1.移動程式
```c++
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslated(0.5,0.5,0);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

2.四茶壺程式
```c++
#include<GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣
        glTranslated(0.5,0.5,0);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    myTeapot(0.5,0.5);
    myTeapot(-0.5,0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(0.5,-0.5);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

3.滑鼠點擊程式
```c++
#include<GL/glut.h>
float mouseX=0,mouseY=0;
void myTeapot(float x,float y)
{
    glPushMatrix();///備份矩陣
        glTranslated(x,y,0);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    mouseX=x; mouseY=y;
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///滑鼠事件

    glutMainLoop();
}

```
