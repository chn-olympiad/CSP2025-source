#include<bits/stdc++.h>
using namespace std;
int n,i,j,f[10];
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(i=1;i<=n;i++)
	   if(a[i]>=48&&a[i]<=57)
	     f[a[i]-48]++;
	for(i=9;i>=0;i--)
	   for(j=1;j<=f[i];j++)
	      putchar(i+48);
	return 0;
}
