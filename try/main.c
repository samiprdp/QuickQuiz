#include<stdio.h>

int main()
{
int number,answer;
printf("Enter the number:");
scanf("%d",&number);
answer = number &1 ;
if(answer==0){
printf("Even\n");
}
else if(answer==1){
printf("odd\n");
}
else{
printf("not allowed");
}
return 0;
}