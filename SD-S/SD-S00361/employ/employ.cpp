#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MX=500;
ll n,m,i,sum=1,a[MX+10];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool f=1;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		for(i=2;i<=n;i++)
		{
			sum=sum*i%mod;
		}
		cout<<sum<<'\n';
	}
	else cout<<0;
	return 0;
}
