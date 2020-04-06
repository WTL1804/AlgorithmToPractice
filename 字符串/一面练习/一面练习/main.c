 

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int a[n];
    int b[n];
    int j;
    for(i=0;i<n+1;i++){
        scanf("%d ",&a[i]);
    }
    for(j=0;j<n;j++){
        b[j]=a[n-j-1];
        printf("%d ",b[j]);
    }
    return 0;
}
