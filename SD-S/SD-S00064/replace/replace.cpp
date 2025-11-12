#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N=1e3+10,INF=1e18+10;
int n,q;
map<pair<string,string>,int>mp;
string s1[N],s2[N];
string t1[N],t2[N];
int ooo[N],oo[N];
int ans;
string ss,sss,ttt,tttt;
string u;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int j=1;j<=n;j++)
	{
		cin>>s1[j]>>s2[j];
		if(s1[j]==s2[j])
		{
			continue;
		}
		int st=0,ed=s1[j].size()-1;
		for(int i=0;i<s1[j].size();i++)
		{
			if(s1[j][i]!=s2[j][i])
			{
				st=i;
				break;
			}
		}
		for(int i=s1[j].size()-1;i>=0;i--)
		{
			if(s1[j][i]!=s2[j][i])
			{
				ed=i;
				break;
			}
		}
		oo[j]=st;
		int len=ed-st+1;
		ooo[j]=s1[j].size();
		t1[j]=s1[j].substr(st,len);
		t2[j]=s2[j].substr(st,len);
		mp[{t1[j],t2[j]}]++;
	}
	while(q--)
	{
		ans=0;
		cin>>ss>>sss;
		int st=0,ed=ss.size()-1;
		for(int i=0;i<ss.size();i++)
		{
			if(ss[i]!=sss[i])
			{
				st=i;
				break;
			}
		}
		for(int i=ss.size()-1;i>=0;i--)
		{
			if(ss[i]!=sss[i])
			{
				ed=i;
				break;
			}
		}
		int len=ed-st+1;
		ttt=ss.substr(st,len);
		tttt=sss.substr(st,len);
		for(int i=1;i<=n;i++)
		{
			int ddd=st-oo[i],eee=ddd+ooo[i]-1;
			if(ddd<0||eee>=ss.size())
			{
				continue;
			}
			u=ss.substr(ddd,ooo[i]);
			if(s1[i]==u&&ttt==t1[i]&&tttt==t2[i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
