#include<stdio.h>
int main(){
    int i,val,n,a[100],j,temp;
     printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     for(i=0;i<n;i++){
       for(j=0;j<n-i;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
      }
     }
     for(i=0;i<n;i++){
        printf("%d   ",a[i]);
     }

    }