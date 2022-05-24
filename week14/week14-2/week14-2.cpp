#include <stdio.h>
int main()
{
    FILE*fout=fopen("file.txt","w+");///指標fout開啟檔案
    fprintf(fout,"3.1415926\n");
    fclose(fout);///關閉檔案

    float angle=0;
    FILE*fin=fopen("file.txt","r");
    fscanf(fin,"%f",&angle);
    printf("讀到了角度:%f",angle);
    fclose(fin);
}
