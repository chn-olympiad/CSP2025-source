#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[501];
int modp=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) l++;
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
	int yi=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') yi++;
	}
	if(yi<m){cout<<0;return 0;}
	if(n-l<m){cout<<0;return 0;}
	if(m==1)
	{
		int f1=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') f1++;
			else break;
		}
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=f1) cc++;
		}
		int ppp=1;
		for(int i=1;i<=n-1;i++)
		{
			ppp=(ppp*i)%modp;
		}
		cout<<(ppp*cc)%modp;
		return 0;
	}
	int ppp=1;
	for(int i=1;i<=n;i++)
	{
		ppp=(ppp*i)%modp;
	}
	cout<<ppp;
	return 0;
}