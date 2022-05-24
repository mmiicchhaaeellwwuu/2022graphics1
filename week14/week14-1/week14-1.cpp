#include <stdio.h>
int main()
{
    FILE*fout=fopen("file.txt","w+");///指標fout開啟檔案
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案
}
