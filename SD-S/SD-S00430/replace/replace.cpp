#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
const int Mod1 = 998244353;
const int Mod2 = 1e9+7;
const int T = 31;
string a[N],b[N];
long long ha[N][2],hb[N][2];
pair<long long,long long> H(string s)
{
	long long x=0,y=0;
	for(auto i:s)
	{
		x=x*T+(i-'a');
		x%=Mod1;
		y=y*T+(i-'a');
		y%=Mod2;		
	}
	return {x,y};
}
long long h[N][2][2];
long long qpow(long long x,long long y,long long Mod)
{
	long long ans=1;
	while(y)
	{
		if(y&1) ans*=x,ans%=Mod;
		x=x*x;x%=Mod;y/=2;
	}
	return ans;
}
map<string,set<string>> mp;
long long ans,n,m;
void solve()
{
	string s,t;
	cin>>s>>t;
	ans=0;
	for(int i=0;i<s.size();i++)
	{	
		for(int j=1;j<=n;j++)
		{
			int len=a[j].size();
			if(i+len-1<s.size())
			{
				
				string tmp="";
				if(i-1>=0) tmp+=s.substr(0,i);
				tmp+=b[j];
				tmp+=s.substr(i+len,s.size()-(i+len));
				if(s.substr(i,len)==a[j]&&tmp==t) ans++;
				 
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],mp[a[i]].insert(b[i]);
	
	while(m--)
	{
		solve();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
