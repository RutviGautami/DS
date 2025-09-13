#include<stdio.h>

void hashset(int v,int set[],int size,int index){
    if(set[index] == -1){
        set[index] = v;
        return;
    }
    else if(set[index] == v){
        printf("you cannot insert duplicate elements\n");
        return;
    }
    else{
        index =  (v % 18) + 2 ;
        hashset(v,set,size,index);
    }
    return;
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d , ",arr[i]);   
    }
}

void input_array(int arr[],int n){
    for(int i=0;i<n;i++){
        int v; 
        printf("Element %d: ",i+1);
        scanf("%d",&v);
        hashset(v,arr,n,v%n);
    }
}

int main(){
    int n;
    printf("Enter size of array");
    scanf("%d",&n);
    int set[n] ;
    for(int i=0;i<n;i++){
        set[i] = -1;
    }
    input_array(set,n);
    print_array(set,n);
    return 0;
}