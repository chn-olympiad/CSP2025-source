#include<bits/stdc++.h>
using namespace std;
long long n,k,a[600000],ans,f[600000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=0,x=0;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) 
		{
			memset(f,0,sizeof(f));
			x=0;
			ans++;
			q=0;
		}
		else
		{
			x++;
			for(int j=1;j<=x;j++)
			{
				f[j]^=a[i];
				if(f[j]==k) 
				{
					memset(f,0,sizeof(f));
					x=0;
					ans++;
					q=0;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/