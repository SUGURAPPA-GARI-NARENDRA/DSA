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
     printf("The numbers you have enterd are :: ");
     for(i= 0;i<n;i++){
        printf("%d , ",a[i]);
     }
       
     //Enter which position you have to insert
     printf("Enter the position  ::  ");
     scanf("%d",&pos);
    
     // main logic
     for(i=n-1;i>=pos;i--){
             a[i+1]=a[i];                                                                    
     }
     printf("\n Enter the what value you have to be inserted = ");
     scanf("%d",&val);
     a[pos]=val;
     n++ ;

     printf("The numbers you have enterd are :: ");
     for(i=0;i<n;i++){
        printf("%d , ",a[i]);
    }
}