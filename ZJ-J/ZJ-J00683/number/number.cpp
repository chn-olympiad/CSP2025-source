#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt;
int a[1000011];
string s;
bool cmp(ll a,ll b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
//dark_knight_ak_all
//lcfollower
//huyao
//qzh120124
//hhztl
//wangchuyue
//b1tset
//robin_kool
//cosm0s
//dream_stars
//dream_sky
//xxxyz
//bjxxzjh
//heyechen
//a_tall_bird
//xsj4zyc
//yaozhuocheng
//Xrange
//lzy
//autumn_kite
//ymq I love you
