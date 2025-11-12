#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll a[20];
string s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
