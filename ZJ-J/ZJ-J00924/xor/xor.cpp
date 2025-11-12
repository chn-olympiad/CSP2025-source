#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500001];
ll p[500001];
ll g[500001];
ll sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[i]=p[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n-i+1;j++)
		{
			int s=p[j+i-1]^p[j-1];
			if(s==k)
			{
				bool sp=0;
				for(ll v=j;v<=j+i-1;v++)sp=sp||g[v];
				if(sp!=1)
				{
					for(ll v=j;v<=j+i-1;v++)g[v]=1;
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
