#include<stdio.h>
int i,j,knap[20][20];
int max(int a, int b) {
 if(a>b){
 return a;
 } else {
 return b;
 }
}
int knapsack(int m, int wt[], int p[], int n) {
 for (i = 0; i <= n; i++)
 {
 for ( j= 0; j<= m; j++)
 {
 if (i==0 || j==0)
 {
 knap[i][j] = 0;
 }
 else if(j-wt[i-1]>=0)
 {
 knap[i][j] = max(p[i-1] + knap[i-1][j-wt[i-1]], knap[i-1][j]);
 }
 else
 {
 knap[i][j] = knap[i-1][j];
 }
 }
 }return knap[n][m];
}
 int printobject(int m, int wt[],int p[])
 {
 i--;j--;
 while(i>0&&j>0)
 {
 if(knap[i][j]==knap[i-1][j])
 {
 i--;
 }
 else
 {
 printf("%d\n",i);
 j=j-wt[i-1];
 i--;
 }
 }
 }
int main()
{
 int p[50],wt[50],m,n;
 printf("Enter number of items:\n ");
 scanf("%d",&n);
 printf("Enter Weights: \n");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&wt[i]);
 }
 printf("Enter profits: \n");
 for(int i=0;i<n;i++)
 {
 scanf("%d",&p[i]);
 }
 printf("Enter Capacity of Knapsack bag: \n");
 scanf("%d",&m);
 printf("Maximum profit is: %d\n", knapsack(m, wt, p, n));
 printf("The Elements Are \n");
 printobject(m,wt,p);
 return 0;
}
