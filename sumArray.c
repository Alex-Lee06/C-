/*C Program to accept & add value of 2 array & display the sum of arrays*/
#include<stdio.h>
#include<conio.h>
void main()
{
 int i,a[5],b[5],c[5];
 clrscr();
 printf("\nReading the 1st array\n");
 for (i=0;i<5;i++)
   {
   printf("Enter the  value");
   scanf("%d",&a[i]);
   }
 printf("\nReading the 2nd array\n");
 for (i=0;i<5;i++)
   {
   printf("Enter the  value");
   scanf("%d",&b[i]);
   }
   printf("\nThe output of addition of 2 array is\n");
   for(i=0;i<5;i++)
     {
     c[i]=a[i]+b[i];
     printf("\nthe sum of %d & %d is %d",a[i],b[i],c[i]);
     }
     getch();
}
