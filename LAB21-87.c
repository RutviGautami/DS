#include<stdio.h>
#include<string.h>

int Linear_Search(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

void input_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

int main(){
    int key,n;
    printf("Size of array: ");
    scanf("%d",&n);
    int arr[n];
    input_array(arr,n);
    printf("Search Element: ");
    scanf("%d",&key);
    int index = Linear_Search(arr,key,n);
    if(index == -1){
        printf("Element not found \n");
        return 1;
    }
    printf("%d found at index : %d",key,index);
    return 0;
}