#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;///�ŧi
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("�H�K���A��J�Ʀr,�{���d��F�o: ");
    int N;
    scanf("%d",&N);
}
