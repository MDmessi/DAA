#include<stdio.h> 
#include<conio.h> 
int gcd(int,int); 
int main() 
{ 
 int a,b,result; 
 printf("Enter the first number: "); 
 scanf("%d",&a); 
 printf("Enter second number:"); 
 scanf("%d",&b); 
 result=gcd(a,b); 
 printf("\n\nThe gcd of two numbers %d and %d is: %d",a,b,result); 
 getch(); 
 return(0); 
  
} 
int gcd(int a,int b) 
{ 
 int r,i=1; 
 if(a==0) 
  return(b); 
 else if(b==0) 
  return(a); 
 else 
 { 
  while(b!=0) 
  { 
   printf("\n %d Iteration\n",i); 
   r=a%b; 
   printf("\t\t%d MOD %d= %d",a,b,r); 
   a=b; 
   b=r; 
   i++; 
  } 
  return(a); 
 } 
}
