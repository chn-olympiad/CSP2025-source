#include<bits/stdc++.h>

using namespace std;

#define ll long long

string s;
ll mp[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;++i)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			mp[s[i]-'0']++;
		}
	}
	bool tf=false;
	for(ll i=1;i<=9;++i) if(mp[i]>=1) tf=true;
	if(tf==false)
	{
		cout<<"0";
		return 0;
	}
	for(ll i=9;i>=0;--i)
	{
		for(ll j=1;j<=mp[i];++j)
		{
			cout<<char(i+'0');
		}
	}
	return 0;
}