#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r","stdin");
    freopen("polygon.out","w","stdout");
	int n,num=0,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		int maxn=a[i];
		for(int j=i;j<=3;j++)
		{
			maxn=max(maxn,a[j]);
		}
		if(a[i]+a[i+1]+a[i+2]>maxn*2)
		{
			num++;
		}
	}
	cout<<nmu;
	return 0;
}>
