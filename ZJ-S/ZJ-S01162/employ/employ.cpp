#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=998244353;
ll fac[510];
int s[510],c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;i++)
	fac[i]=fac[i-1]*i;
	cin>>n>>m;
	char cc;
	for(int i=1;i<=n;i++)
	{
		cin>>cc;
		s[cc-'0']++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cnt[c[i]]++;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0||c[i]==0)
			{
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<fac[n];
		return 0;
	}
	cout<<fac[n];
	return 0;
}
