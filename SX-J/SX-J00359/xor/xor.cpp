#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],mmax;
bool vis[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			bool f=1;
			for(int i=l;i<=r;i++)
			{
				if(vis[i]==1)
				{
					f=0;
				}
			}
			if(f)
			{
				long long x=a[l];
				for(int i=l+1;i<=r;i++)
				{
					x^=a[i];
				}
				if(x==k)
				{
					mmax++;
					for(int i=l;i<=r;i++)
					{
						vis[i]=1;
					}
				}
			}
		}
	}
	cout<<mmax;
	return 0;
}
