#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,f[5010];
long long m;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]<a[i]+a[j])
				{
					s++;
					s%=998244353;
				}
			}
		}
	}
	cout<<s;
	return 0;
	
}
