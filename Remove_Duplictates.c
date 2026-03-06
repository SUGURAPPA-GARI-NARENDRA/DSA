#include<stdio.h>
int main(){
    int i,n,a[100],val,pos,temp[100],j=0;

    //eneter how many numbers 
    printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
      temp[j] = a[0];
      for(i=1;i<n;i++){
        if(a[i]!=a[i-1]){
          j++;
          temp[j]=a[i];
         
          //j++;
          
        }
      }
        for(i=0;i<=j;i++){
            
            printf("%d ",temp[i]);
        }
        return 0;
      }
