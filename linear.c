#include<stdio.h>
int main(){
    int i,val,n,a[100];
     printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }

    printf("Enter value to search  ");
    scanf("%d",&val); 
    for(i=0;i<n;i++){
        if(a[i]==val){
            printf("the value will be present at %d",i);
        }
        }
    }
