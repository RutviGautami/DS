#include<stdio.h>

void Merge(int left,int mid,int right,int a[]){
    int b[right-left+1];
    int h = left,i = left,j = mid+1,k;
    do{
        if(a[h] <= a[j]){
            b[i] = a[h];
            h++; 
        }
        else{
            b[i] = a[j];
            j++;
        }
        i++;
    }while(h<=mid && j<=right);
    if(h > mid){
        for(k=j;k<=right;k++){
            b[i] = a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){
            b[i] = a[k];
            i++;
        }
    }
    for(k=left;k<=right;k++){
        a[k] = b[k];
    }
}

void Merge_Sort(int left,int right,int a[]){
    if(left < right){
        int mid = (left+right)/2;
        Merge_Sort(left,mid,a);
        Merge_Sort(mid+1,right,a);
        Merge(left,mid,right,a); 
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
        scanf("%d ",&arr[i]);
    }
}

int main(){
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    int arr[n];
    input_array(arr,n);
    Merge_Sort(0,n-1,arr);
    print_array(arr,n);
    return 0;
}