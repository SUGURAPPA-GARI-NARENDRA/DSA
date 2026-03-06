#include<stdio.h>
int main(){
    int i,n,a[100],val,pos;

    //eneter how many numbers 
    printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
      
    //Traversing the array 
     //printf("The numbers you have enterd are :: ");
    // for(i= 0;i<n;i++){
     //   printf("%d , ",a[i]);
   //  }
      //Deleting at the end 
     //n--;
     printf("Enter positiopn :: ");
     scanf("%d",&pos);
     
      for(i=pos;i<n;i++){
             a[i-1]=a[i];                                                                     
     }
     //Deleting at the front
      n--;
      //The updated array
     printf("\n The updated array is :: ");
     for(i= 0;i<n;i++){
        printf("%d  ",a[i]);
     }

    }

