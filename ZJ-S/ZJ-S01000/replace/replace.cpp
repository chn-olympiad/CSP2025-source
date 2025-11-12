#include<bits/stdc++.h>//368346,ciallo
using namespace std;
#define ll long long
#define fre(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout)
const ll maxn=10009;
map<string,string>m;
map<string,bool>vis;
ll n,q,cnt;
string s1,s2;
string sa1,sa2,sa3;
void dfs(string s,ll o)
{
	if(s==s2)
	{
		cnt++;
		return void();
	}
	if(o==1)
	{
		return void();
	}
	for(ll l=0;l<s.size();l++)
	{
		for(ll r=l;r<s.size();r++)
		{
			sa1="";
			sa2="";
			sa3="";
			for(ll i=0;i<l;i++)
			{
				sa1+=s[i];
			}
			for(ll j=r+1;j<s.size();j++)
			{
				sa2+=s[j];
			}
			for(ll j=l;j<=r;j++)
			{
				sa3+=s[j];
			}
			if(vis[sa3]==1)
			{
				sa3=m[sa3];
				dfs(sa1+sa3+sa2,1);
			}
		}
	}
}
int main()
{
	fre(replace);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(q>1e3)
	{
		while(q--)
		{
			cout<<0<<endl;
		}
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		m[s1]=s2;
		vis[s1]=1;
	}
	for(ll i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		cnt=0;
		dfs(s1,0);
		cout<<cnt<<endl;
	}
	return 0;
}
