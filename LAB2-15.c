#include<stdio.h>
#include<math.h>

int countnumber(int n){
    int count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    return count;
}

int main(){
    int sum=0,power,temp;
    for(int i=1;i<=1000;i++){
        temp=i;
        power=countnumber(i);
        for(int j=1;j<=power;j++){
            sum=sum+pow(i%10,power);
            i=i/10;
        }
        if(temp==i){
            printf("%d,",temp);
        }
    }
}