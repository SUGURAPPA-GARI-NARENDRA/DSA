#include<stdio.h>
int main(){
    int i,n,a[100],low,mid,high,val;
    //eneter how many numbers 
    printf("Enter the how many number you have  =  ");
    scanf("%d",&n);

    // taking input from the user 
     printf("Enter the Number :: ");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }

      printf("Enter value to search  ");
    scanf("%d",&val); 
    low = 0,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(val<a[mid]){
            high = mid-1;
        }
        else if(val>a[mid]){
            low = mid +1;
        }
        else{
            printf("the value will be found at %d",mid+1);
            break;
        }
    }


}