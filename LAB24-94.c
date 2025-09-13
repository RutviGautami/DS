#include<stdio.h>

void Quick_Sort(int ub,int lb,int a[]){
    int flag = 1;
    if(lb<ub){
        int i = lb;
        int j = ub+1;
        int key = a[lb];
        while(flag == 1){
            i++;
            while(a[i] < key){
                i++;
            }
            j--;
            while(a[j] > key){
                j--;
            }
            if(i<j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else{
                flag = 0;
            }
        }
        int temp = a[lb];
        a[lb] = a[j];
        a[j] = temp;
        Quick_Sort(j-1,lb,a);
        Quick_Sort(ub,j+1,a);
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
    Quick_Sort(n-1,0,arr);
    print_array(arr,n);
    return 0;
}