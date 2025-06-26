#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void main(){
    int n;
    printf("Enter total numbers: ");
    scanf("%d",&n);
    char a[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",&a[i]);
    }
    srand(time(0));
    int rn= rand() % n;
    printf("%d \n",rn);
    char ana[100];
    scanf("%s",&ana);
    for (int i = 0; a[rn][i] != '\0'; i++) {
        for (int j = i + 1; a[rn][j] != '\0'; j++) {
           if(a[rn][i]>a[rn][j]){
            a[rn][i]=a[rn][j]+a[rn][i];
            a[rn][j]=a[rn][i]-a[rn][j];
            a[rn][i]=a[rn][i]-a[rn][j];
           }
           if(ana[i]>ana[j]){
            ana[i]=ana[j]+ana[i];
            ana[j]=ana[i]-ana[j];
            ana[i]=ana[i]-ana[j];
           }
        }
    }
    puts(a[rn]);
    puts(ana);
    if(strcmp(ana,a[rn])!=0){
        printf("not valid");
    }
    else{
        printf("valid");
    }
}