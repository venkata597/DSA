#include <stdio.h>

void minmax(int arr[],int low,int high,int* min,int* max){
    int min1,min2,max1,max2;
    if(low==high){
        *min = arr[low];
        *max = arr[low];
    }
    else if(low==high-1){
        if(arr[low]<arr[high]){
            *min = arr[low];
            *max = arr[high];
        }
        else{
            *min = arr[high];
            *max = arr[low];
        }
    }
    else{
        int mid = (low+high)/2;
        minmax(arr,low,mid,&min1,&max1);
        minmax(arr,mid+1,high,&min2,&max2);
        if(min1<min2){
            *min = min1;
        }
        else{
            *min = min2;
        }
        if(max1>max2){
            *max = max1;
        }
        else{
            *max = max2;
        }
    }
}

int main(){
    // Sample Test Case, Running out of time to write user-driven
    int a[] = {3,1,8,5};
    int min=0,max=0;
    int *minimum = &min;
    int *maximum = &max;
    minmax(a,0,3,minimum,maximum);
    printf("Minimum in the array: %d\n",*minimum);
    printf("Maximum in the array: %d\n",*maximum);
}