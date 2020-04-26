#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val, double ave, double square_ave);
double count = 0;
double ave = 0;
double var = 0;
double square_ave = 0;

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        count = count + 1;
        var = var_online(val,ave,square_ave);
        ave = ave_online(val,ave);
        square_ave = ave_online(val*val,square_ave);
    
    }

    printf("average=%lf\n",ave);
    printf("variance=%lf\n",var);
    printf("population_average=%lf\n",ave);
    printf("population_variance=%lf\n",(((count - 1)/count))*var);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    
    return 0;



}

double ave_online(double val,double ave){

    return (((count-1)/count)*ave) + (val/count);

}

double var_online(double val, double ave, double square_ave){

    return (square_ave)-(ave*ave);
}




