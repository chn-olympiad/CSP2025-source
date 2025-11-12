//by xt66666
//TYZ 
// uid:อüมห 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[1000010];
ll cmp(ll x,ll y)
{
	return x>y;
}
ll cnt;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("number4.in","r",stdin);
	//freopen("number.ans","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=(ll)(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}

