#include <stdio.h>
int arr[100],n;
void display()
{
 int i;
 if(n==0)
 {
 printf("Heap is empty\n");
 return;
 }
 for(i=0; i<n; i++)
 printf("%d ",arr[i]);
 printf("\n");
}
void insert(int num,int loc)
{
 int par;
 while(loc>0)
 {
 par=(loc-1)/2;
 if(num<=arr[par])
 {
 arr[loc]=num;
 return;
 }
 arr[loc]=arr[par];
 loc=par;
 }
 arr[0]=num;
}
void del(int num)
{
 int left,right,i,temp,par;
 for(i=0; i<n; i++)
 {
 if(num==arr[i])
 break;
 }
 if( num!=arr[i] )
 {
 printf("%d not found in heap\n",num);
 return;
 }
 arr[i]=arr[n-1];
 n=n-1;
 par=(i-1)/2;
 if(arr[i] > arr[par])
 {
 insert( arr[i],i);
 return;
 }
 left=2*i+1;
 right=2*i+2;
 while(right < n)
 {
 if( arr[i]>=arr[left] && arr[i]>=arr[right] )
 return;
 if( arr[right]<=arr[left] )
 {
 temp=arr[i];
 arr[i]=arr[left];
 arr[left]=temp;
 i=left;
 }
 else
 {
 temp=arr[i];
 arr[i]=arr[right];
 arr[right]=temp;
 i=right;
 }
 left=2*i+1;
 right=2*i+2;
 }
 if( left==n-1 && arr[i]<arr[left] )
 {
 temp=arr[i];
 arr[i]=arr[left];
 arr[left]=temp;
 }
}
main()
{
 int choice=0,num;
 n=0;
 while(choice!=4)
 {
 printf("1.Insert\n");
 printf("2.Delete\n");
 printf("3.Display\n");
 printf("4.Quit\n");
 printf("Enter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("Enter the number to be inserted : ");
 scanf("%d",&num);
 insert(num,n);
 n=n+1;
 break;
 case 2:
 printf("Enter the number to be deleted : ");
 scanf("%d",&num);
 del(num);
 break;
 case 3:
 display();
 break;
 case 4:
 break;
 default:
 printf("Wrong choice\n");
 }
 }
}