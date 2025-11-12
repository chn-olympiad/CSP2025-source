#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
unordered_map<string,string>mp;
int n,q;
void solve()
{
	ll ans=0;
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size())
	{
		printf("0\n");
		return;
	}
	int l=s1.size();
	s1=" "+s1;
	for(int len=1;len<=l;len++)
	{
		for(int i=1;i+len-1<=l;i++)
		{
			string y=s1.substr(i,len);
			if(!mp.count(y))continue;
			string x=s1.substr(1,i-1),z=s1.substr(i+len,l-len-i+1);
			string tmp=x+mp[y]+z;
			if(tmp==s2)ans++;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--)solve();
	return 0;
}
