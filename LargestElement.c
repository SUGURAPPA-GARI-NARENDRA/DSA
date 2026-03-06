#include<stdio.h>
int main(){
    int i,n,a[100],val,largest,j;

    //eneter how many numbers 
    printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
      
    //Traversing the array 
     printf("The numbers you have enterd are :: ");
     for(i= 0;i<n;i++){
        printf("%d , ",a[i]);
     }
     //main logic
    largest = a[0];
     for(i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                largest = a[i+1];
            }
        }
        printf("Largest Value is :: %d",largest);
     }
    /*
    if the array is sorted the the second largest element is 
     largest = a[0];
     for(i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                largest = a[i];
            }
        }
        printf("Largest Value is :: %d",largest);
     }    
    */