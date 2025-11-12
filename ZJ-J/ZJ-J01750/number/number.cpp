#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
map<char,int> mp;
ll n,m,t,k,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.size();
	for(ll i=0;i<n;i++)
	{
		mp[s[i]]++;
	}
	for(ll i=1;i<=mp['9'];i++)
	{
		cout<<9;
	}
	for(ll i=1;i<=mp['8'];i++)
	{
		cout<<8;
	}
	for(ll i=1;i<=mp['7'];i++)
	{
		cout<<7;
	}
	for(ll i=1;i<=mp['6'];i++)
	{
		cout<<6;
	}
	for(ll i=1;i<=mp['5'];i++)
	{
		cout<<5;
	}
	for(ll i=1;i<=mp['4'];i++)
	{
		cout<<4;
	}
	for(ll i=1;i<=mp['3'];i++)
	{
		cout<<3;
	}
	for(ll i=1;i<=mp['2'];i++)
	{
		cout<<2;
	}
	for(ll i=1;i<=mp['1'];i++)
	{
		cout<<1;
	}
	for(ll i=1;i<=mp['0'];i++)
	{
		cout<<0;
	}
	return 0;
}
