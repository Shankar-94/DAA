#include <stdio.h>
#include <time.h>
#include <windows.h>
void SortByCounting(int a[],int n);
int main()
{
 int n,i;
 int a[100];
 printf("Enter array size: ");
 scanf("%d",&n);
 printf("Enter array Elements\n");
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 }
 SortByCounting(a, n);
 printf("\nSorted Elements are: \n");
 for(i=0;i<n;i++){
 printf("%d ",a[i]);
 }
 return 0;
}
void SortByCounting(int a[],int n){
 int i,j, count[n], b[n];
for(i=0;i<n;i++){
count[i]=0;
b[i]=a[i];
}
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(a[i]<a[j])
count[j]=count[j] + 1;
else
count[i]=count[i] + 1;
}
}
for(i=0;i<n;i++){
a[count[i]]=b[i];
}
}
