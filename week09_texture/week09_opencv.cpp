#include<opencv/highgui.h>//使用opencv外掛
int main()
{
    IplImage * img=cvLoadImage("北海道神宮.jpg");//讀圖
    cvShowImage("week09",img);//秀圖
    cvWaitKey(0);//等待任意鍵;
}
