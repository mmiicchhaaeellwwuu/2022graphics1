#include<opencv/highgui.h>//�ϥ�opencv�~��
int main()
{
    IplImage * img=cvLoadImage("�_���D���c.jpg");//Ū��
    cvShowImage("week09",img);//�q��
    cvWaitKey(0);//���ݥ��N��;
}
