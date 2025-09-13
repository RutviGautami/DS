#include<stdio.h>

void Insertion_Sort(int a[],int n){
    for(int i=0;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key ){
            a[j+1] = a[j];
            j--;                 
        }
        a[j+1] = key;
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d , ",arr[i]);   
    }
}

void input_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

int main(){
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    int arr[n];
    input_array(arr,n);
    Insertion_Sort(arr,n);
    print_array(arr,n);
    return 0;    
}