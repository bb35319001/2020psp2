#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA
{
    int gender;
    double height;
    int id;
}data;

int main(void)
{
    char fname1[FILENAME_MAX], fname2[FILENAME_MAX];
    char buf[256];
    FILE* fp1;
    FILE* fp2;
    int i;
    int gender;
    double height;
    int id;
    int getid;
    struct DATA data [14];

    printf("input the filename of sample heights:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';

    printf("input the filename of sample ID:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp1) != NULL)
    {
        sscanf(buf,"%d,%lf",&gender,&height);
        data[i].gender = gender;
        data[i].height = height;
        i++;
    }

    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp2) != NULL)
    {
        sscanf(buf,"%d",&id);
        data[i].id = id;
        i++;
    }

    printf("Which ID's data do you want?: ");
    scanf("%d",&getid);

    printf("---\n");

    for(i=0;i<15;i++)
    {
        if(getid == data[i].id)
        {
            if(data[i+1].gender == 1)
            {
                printf("ID : %d\n",getid);
                printf("gender : Male\n");
                printf("height : %.2lf\n",data[i+1].height);
            }else
            {
                printf("ID : %d\n",getid);
                printf("gender : Female\n");
                printf("height : %.2lf\n",data[i+1].height);
            }
            i++;
        }       
    }

    if(getid != data[i].id)
    {
        printf("No data\n");
    }

    printf("---\n");

     if(fclose(fp1) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;
}
