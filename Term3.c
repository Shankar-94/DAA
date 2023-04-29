#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int arr[100];
void merge_sort(int low, int high)
{
 if(low!=high)
 {
 int mid;
 mid=(low+high)/2;
 merge_sort(low,mid);
 merge_sort(mid+1,high);
 merge(low,mid,high);
 }
}
void merge(int low, int mid, int high)
{
 int temp[1000];
 int i=low;
 int k=low;
 int j=mid+1;
 while((i<=mid)&&(j<=high))
 {
 if(arr[i]<=arr[j])
 temp[k++]=arr[i++];
 else
 temp[k++]=arr[j++];
 }
 while(i<=mid)
 temp[k++]=arr[i++];
 while(j<=high)
 temp[k++]=arr[j++];
 for(i=low;i<=high;i++)
 arr[i]=temp[i];
}
void main()
{
 double time_spent =0.0;
 clock_t begin = clock();
 int i,j,n;
 printf("Merge Sort Program\n");
 printf("Enter The Size of the Array:\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 arr[i]=rand()%100;
 printf("Random Array Are :\n");
 for(i=0;i<n;i++)
 printf("%d \t ",arr[i]);
 merge_sort(0,n-1);
 printf("\nMerge Sort is :");
 for(i=0;i<n;i++)
 printf("%d \t",arr[i]);
 clock_t end = clock();
 time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
 printf("\n The elapsed time is %f seconds",time_spent);
}
