#include <stdio.h>
int main()
{
    FILE*fout=fopen("file.txt","w+");///����fout�}���ɮ�
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///�����ɮ�
}
