#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int a[505],k[505],c[505],T[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=a[i-1]+1;
		if(ch=='1')
		{
			a[i]-=1;
			k[++t]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=t;j>=1;j--)
		{
			if(a[k[j]]<c[i])
			{
				T[k[j]]++;
				break;
			}
		}
	}
	long long solve=0;
	for(int i=0;i<(1<<(t+1));i++)
	{
		int kx=i,p=0,x=1;
		long long ans=1;
		while(kx!=0)
		{
			if(kx&1)
			{
				p++;
				ans=(ans%998244353*T[k[x]]%998244353)%998244353;
			}
			kx>>=1;
			x++;
		}
		if(p==m)
		{
			if(n-m!=0)
			{
				ans=(ans%998244353*(n-m))%998244353;
			}	
			solve=(solve%998244353+ans)%998244353;
		}
	}
	cout<<solve;
	return 0;
} 
