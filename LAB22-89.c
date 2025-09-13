#include<stdio.h>
#include<string.h>

void Bubble_Sort(int arr[],int n){
    int swap = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp; 
                swap++;
            }
        } 
    }
    printf("swaps : %d\n",swap);  
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
    Bubble_Sort(arr,n);
    print_array(arr,n);
    return 0;
}