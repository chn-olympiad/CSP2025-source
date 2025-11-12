#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[101]={0};
	scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
}
int sum=0;
for(int i=1;i<=n-2;i++)
{
	sum+=i;
}
	printf("%d",sum);
	return 0; 
}
