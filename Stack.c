#include<stdio.h>
#define Max 5
int Stack[Max];
int top=-1;
void push(int n){
    if(top>=Max-1){
        printf("\n The Stack is Overflow?");
    }
    else{
        top++;
        Stack[top]=n;
        printf("%d",n);
    }
}
void pop(){
    if(top==-1){
        printf("Deleting the element :: %d ",Stack[top]);
        printf("\n UnderFlow");
    }
    else{
        top--;
    }
}
int main(){
push(10);
push(30);
push(60);
push(20);
pop();
pop();
pop();
pop();
}