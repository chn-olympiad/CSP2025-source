#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;
const ll M=1005;
ll n,m,T,a[N],f[M][M],ans;

bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ll x=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll y=1;
	for(int i=1;;)
	{
		bool flag=0;
		for(int j=1;;)
		{
			f[i][j]=a[y];
			y++;
			if(i<n&&i>1)
			{
				if(j%2==1)
				{
					i++;
				}
				else
				{
					i--;
				}
			}
			else
			{
				if(i==1&&j%2==1)
				{
					i++;
				}
				if(i==1&&j%2==0)
				{
					j++;
				}
				if(i==n&&j%2==0)
				{
					i--;
				}
				if(i==n&&j%2==1)
				{
					j++;
				}
			}
			if(i>n||j>m)
			{
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x==f[i][j])
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 

