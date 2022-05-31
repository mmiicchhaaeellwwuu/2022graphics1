#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;///宣告
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("隨便等你輸入數字,程式卡住了囉: ");
    int N;
    scanf("%d",&N);
}
