# 2022graphics1
# week01

## 第一個OpenGL程式
```
0. CodeBlocks 17.12 mingw 裝好
1. File-New-Project，選OpenGL專案
2. 在[...]的目錄，選「桌面」，week 01_OPENGL





3.下一步下一步，完成後，齒輪播放
4.會有彩色三角型旋轉
\Desktop\freeglut


```
## 第一個 GLUT 專案
```
1.moodle下載 freeglut ... zip
2.解壓縮 桌面 freeglut目錄
3.桌面>freeglut>lib的libfreeglut.a將其複製並改成libglut32.a
4.CodeBlocks：File-New-Project，選GLUT
5.取名week01_GLUT
6.設定GLUT目錄 C:\Users\        \Desktop\freeglut





7.齒輪播放後有6個紅東西再轉   




``` 
## 3.git
```
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
# week02
## step01-1 跑範例
```
1.下載範例 http://jsyeh.org/3dcg10     data.zip   windows.zip   glut32.dll
2.window.zip  解壓  下載\windows\Shapes.exe
   data.zip  解壓  下載\windows\data\模型
   glut32.dll  複製  下載\windows\glut32.dll
3.跑Shapes.exe
   右鍵點左半部：大頂點、顏色
   右鍵點右半部：point~polygon




```
## step01-2 跑上週程式
```
1.安裝git for windows
2.git bash：cd desktop，git clone 網址 cd 2022graphicsl
3.安裝freeglut，改檔名lib\libglut32.a 
4.codeblocks file-open week01_GLUT


```
## step02-1 寫程式
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
## step03-1 寫程式
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

# week03
## step01：
```
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

## step02：

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
4.座標換算程式
```c++
#include<GL/glut.h>
#include<stdio.h>
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
    printf("%d %d %d %d\n",button,state,x,y);
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

# week04
## step01主題：rotate旋轉
```
1.http://jsyeh.org/3dcg10下載
  windows.zip >下載\windows\Transformation.exe
  data.zip >下載\windows\data\一堆3D模型
  
(0,0,0)左上右下轉
(1,0,0)前後轉
(0,1,0)左右轉
(1,0,0)2D左右轉
(1,0,1)右上左下轉
(1,1,0)左上右下轉
(1,1,1)右下>頭頂>原點
```
## step02  旋轉茶壺程式
```c++
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(90, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 rotate");
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠拖曳旋轉茶壺程式
```c++
#include<GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle=x;
    display();///重畫畫面
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 rotate");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
## step03 滑鼠點擊拖曳旋轉茶壺程式
```c++
#include<GL/glut.h>
float angle=0,oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle+=(x-oldx);
    oldx=x;
    display();///重畫畫面
}
void mouse(int bitton,int state,int x,int y)
{
    oldx=x;///定錨
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 rotate");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutMainLoop();
}
```

# week05
## step01
```
1.http://jsyeh.org/3dcg10下載
  windows.zip >下載\windows\Transformation.exe
  data.zip >下載\windows\data\模型
  下面有可交換的2行程式碼
```
## 鍵盤&座標程式
```c++
#include<GL/glut.h>
#include<stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,1);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    printf("你按下了 %c 在 %d %d 座標\n",key,x,y);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
```
## step02
1.
```c++
#include<GL/glut.h>
#include<stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,1);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    
}
void mouse(int button,int state,int x,int y)
{
    
}
void motion(int x,int y)
{
    
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
2.
```c++
#include<GL/glut.h>
#include<stdio.h>
float x=0,y=0,z=0;
int oldX=0,oldY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glColor3f(1,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{

}
void motion(int mouseX,int mouseY)
{
    x+=(mouseX-oldX);  y+=(mouseY-oldY);
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
3.
```c++
#include<GL/glut.h>
#include<stdio.h>
float x=150,y=150,z=0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///RGBA,A是半透明功能,目前未開放
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glColor3f(1,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    x+=(mouseX-oldX);  y+=(mouseY-oldY);
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
## step03
## 縮放程式
```c++
#include<GL/glut.h>
#include<stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///RGBA,A是半透明功能,目前未開放
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///縮放scale倍
        glColor3f(1,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX>0) scale*=1.01;
    if(mouseX-oldX<0) scale*=0.99;
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```

# week06打光
## step01
```
1.http://jsyeh.org/3dcg10下載

  windows.zip >下載\windows\Light Material.exe

  data.zip >下載\windows\data\模型

左上:左鍵drag可旋轉

        右鍵，換模型

左下:右鍵，換Material(打光)
```
## step02
## 打光程式
```c++
#include<GL/glut.h>
const GLfloat light_ambient[]={0.0f,0.0f,0.0f,1.0f};
const GLfloat light_diffuse[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[]={2.0f,5.0f,-5.0f,0.0f};

const GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[]={0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[]={100.0f};
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
    glutCreateWindow("week06 light");
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glMaterialfv(GL_FRONT,GL_AMBIENT,light_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,light_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,light_specular);
    glMaterialfv(GL_FRONT,GL_POSITION,light_position);

    glutMainLoop();
}
```
## 上週程式打光
```c++
#include<GL/glut.h>
#include<stdio.h>
const GLfloat light_ambient[]={0.0f,0.0f,0.0f,1.0f};
const GLfloat light_diffuse[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[]={2.0f,5.0f,-5.0f,0.0f};

const GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[]={0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[]={100.0f};
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///RGBA,A是半透明功能,目前未開放
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///縮放scale倍
        glColor3f(1,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX>0) scale*=1.01;
    if(mouseX-oldX<0) scale*=0.99;
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light material");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glMaterialfv(GL_FRONT,GL_AMBIENT,light_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,light_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,light_specular);
    glMaterialfv(GL_FRONT,GL_POSITION,light_position);

    glutMainLoop();
}
```
## step03
## 打光旋轉
```c++
#include<GL/glut.h>
#include<stdio.h>
const GLfloat light_ambient[]={0.0f,0.0f,0.0f,1.0f};
const GLfloat light_diffuse[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[]={2.0f,5.0f,-5.0f,0.0f};

const GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[]={0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[]={100.0f};
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///RGBA,A是半透明功能,目前未開放
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotated(angle,0,1,0);///對y軸轉動
        glScalef(scale,scale,scale);///縮放scale倍
        glColor3f(1,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    angle+=(mouseX-oldX);
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light material");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glMaterialfv(GL_FRONT,GL_AMBIENT,light_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,light_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,light_specular);
    glMaterialfv(GL_FRONT,GL_POSITION,light_position);

    glutMainLoop();
}
```
## 打光 鍵盤 滑鼠 移動
```c++
#include<GL/glut.h>
#include<stdio.h>
const GLfloat light_ambient[]={0.0f,0.0f,0.0f,1.0f};
const GLfloat light_diffuse[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[]={2.0f,5.0f,-5.0f,0.0f};

const GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[]={0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[]={100.0f};

float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=1;///now:1移動 2轉動 3縮放
void display()
{
    glClearColor(0.5,0.5,0.5,1);///RGBA,A是半透明功能,目前未開放
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotated(angle,0,1,0);///對y軸轉動
        glScalef(scale,scale,scale);///縮放scale倍
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{
    if(key=='1'||key=='w'||key=='W') now=1;
    if(key=='2'||key=='e'||key=='E') now=2;
    if(key=='3'||key=='r'||key=='R') now=3;
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    angle+=(mouseX-oldX);
    oldX=mouseX;   oldY=mouseY;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light material");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glMaterialfv(GL_FRONT,GL_AMBIENT,light_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,light_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,light_specular);
    glMaterialfv(GL_FRONT,GL_POSITION,light_position);

    glutMainLoop();
}
```

# week08
## step01
1.http://jsyeh.org/3dcg10下載
  windows.zip >下載\windows\Light Material.exe
  data.zip >下載\windows\data\模型
  source.zip 
執行Light Material.exe(打光/模型)
複習上次上課的範例
2.freeglut安裝  偷程式放notepad++
3.了解glut範例sample.cpp
```c++
glPushMatrix();//備份矩陣
    glTranslatef(x,y,z);//移動
    glRotatef(角度,x,y,z);//轉動
    glScalef(x,y,z);//縮放
glPopMatrix();//還原矩陣
```
4.從github拿上次的程式 week06_light
git 下載上次的程式
git clone下來
把week06_light\main.cpp用notepad++開起來，copy paste到week08的main.cpp
## step02
1.

```c++

#include<GL/glut.h>

#include"glm.h"//雙引號，同目錄裡的檔案

```



```c++

GLMmodel* pmodel=NULL;

```



```c++

void

drawmodel(void)

{

    if(!pmodel)

    {

        pmodel=glmReadOBJ("datd/soccerball.obj");

        if(!pmodel) exit(0);

        glmUnitize(pmodel);

        glmFaceNormals(pmodel);

        glmVertexNormals(pmodel,90,0);

    }

glmDraw(pmodel,GLM_SMOOTH);

}
```

2.畫模型

(1)用drawmodel()

(2)檔案在walking dir工作目錄

(3)在codeblocks下方藍色build log 說工作目錄在......

(4)C:\User\...\Desktop\freeglut\bin\

(5)剛剛下載的 下載\data.zip裡面的data資料夾，整包放在"工作目錄"

(6)把glm.h還有glm.c(檔名改成glm.cpp)放到week08裡

(7)注:附檔名要看到才行

(8)在week08 model專案哩，add同目錄裡的glm.cpp

# week09
## step01
```
1.http://jsyeh.org/3dcg10下載

  windows.zip >下載\windows\Texture.exe

  data.zip >下載\windows\data\圖檔

  source.zip 

Texture.exe 貼圖

2.下載OpenCV 2.1.0 vs2008 版
```

## step02
```
codeblocks要重開

1.File-New-EmptyFile,存成week09_opencv.cpp

2.Setting-Compiler設定Include目錄

3.Setting-Compiler設定Lib目錄

4.Setting-Compiler  Linker加cv210  cxcore210  highgui210



search directories 目錄在哪

compiler 的 Include目錄:c:\opencv2.1\include

Linker的Lib目錄 c:\opencv2.1\lib
```
```c++

#include<opencv/highgui.h>//使用opencv外掛

int main()

{

        IplImage * img=cvLoadImage("檔名.png");//讀圖

        cvShowImage("week09",img);//秀圖

        cvWaitKey(0);//等待任意鍵;

}

```

## step03
File-New-Project,GLUT專案 week09_texture

10行glut範例+opencv讀圖秀圖
