#include<stdio.h>
#include<conio.h>



//  arr[10] = {10, 20 , 30 , 40 , 50 , 60 , 70, 80 , 90 , 00 }


void insertArrBeg(int *arr[], int item, int pos){
    int arr[10]={};
    int n ;
    int i = 0;
    if(n = 10 ){
        printf("The array is full and more elements cannot be inserted......Please delete some elements to insert more elements");
    }
    else{
        n = n+1; 
        for(i = n-1; i>0; i--){
            arr[i]= arr[i-1];
        }
        arr[0]=item;
    }
}

int main(){
    
}