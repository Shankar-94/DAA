#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int arr[100];
void insertion_sort(int arr[], int n)
{
 int i,j,temp;
 for(i=1;i<n;i++)
 {
 temp=arr[i];
 j=i-1;
 while(j>=0 && arr[j]>temp)
 {
 arr[j+1]=arr[j];
 j=j-1;
 }
 arr[j+1]=temp;
 }
}
void main()
{
 double time_spent =0.0;
 clock_t begin = clock();
 int i,j,n;
 printf("Insertion Sort Program\n");
 printf("Enter the Size of the Array:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 arr[i]=rand()%100;
 printf("Random Array Are :\n");
 for(i=0;i<n;i++)
 printf("%d \t ",arr[i]);
 insertion_sort(arr,n);
 printf("\nInsertion Sort is :");
 for(i=0;i<n;i++)
 printf("%d \t",arr[i]);
 clock_t end = clock();
 time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
 printf("\n The elapsed time is %f seconds",time_spent);
}
