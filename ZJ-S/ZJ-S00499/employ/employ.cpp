#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nx[510],zd;
string s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>nx[i];
		zd=max(zd,nx[i]);
	}
	if(zd==1)
	{
		ll i=1,sl=0;
		while(s[i]!='0')
		{
			sl++;
			i++;
		}
		if(sl<m)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
		return 0;
	}
	return 0;
}
