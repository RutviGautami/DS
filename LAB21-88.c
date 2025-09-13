#include<stdio.h>

int Binary_Search_Iterative(int arr[],int key,int n){
    int left=0,right=n-1,middle;
    while(left<=right){
        middle=(left+right)/2;
        if(key == arr[middle]){
            return middle;
        }
        else if(key < arr[middle]){
            right = middle-1;
        }
        else if(key > arr[middle]){
            left = middle+1;
        }
    }
    return -1;
}

int Binary_Search_Recusive(int arr[],int key,int left,int right){
    if(left>right){
        return -1;
    }
    int middle=(left+right)/2;
    if(key == arr[middle]){
        return middle;
    }
    else if(key < arr[middle]){
        return Binary_Search_Recusive(arr,key,left,middle-1);
    }
    else if(key > arr[middle]){
        return Binary_Search_Recusive(arr,key,middle+1,right);
    }
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
    int index = Binary_Search_Iterative(arr,key,n);
    if(index == -1){
        printf("Element not found \n");
    }
    else{
        printf("%d found at index : %d\n",key,index);
    }
    index = Binary_Search_Recusive(arr,key,0,n-1);
    if(index == -1){
        printf("Element not found \n");
    }
    else{
        printf("%d found at index : %d\n",key,index);
    }
    return 0;
}