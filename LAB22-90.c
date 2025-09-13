#include<stdio.h>
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d,",arr[i]);   
    }
}

void Selection_Sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        if(min == i) break;
        a[i] = a[min]+a[i];
        a[min] = a[i]- a[min];
        a[i] = a[i]- a[min];
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
    Selection_Sort(arr,n);
    print_array(arr,n);
    return 0;    
}