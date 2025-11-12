#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long cnt,mili;
long long a[100005];
long long g[4999][4999];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int o=1;
		while(x)
		{
			cnt+=x%2*o;
			o*=10;
			x/=2;
		}
		a[i]=cnt;
		cnt=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long u=g[i][j-1]+a[i]^a[j];
			int d=1;
			while(u)
			{
				g[i][j]+=u%10*d;
				u/=10;
				d*=2;
			}
		}
	}
	for(int p=1;p<=n;p++)
	{
		long long cnt=0;
		for(int i=p;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(g[i][j]==k)
				{
					cnt++;
					i=j;
					j=i+1;
				}
			}
		}
		mili=max(mili,cnt);
	}
	cout<<mili;
	return 0;
}


