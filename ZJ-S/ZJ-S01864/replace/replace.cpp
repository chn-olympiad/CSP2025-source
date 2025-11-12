#include<bits/stdc++.h>
using namespace std;
const int maxn= 2e5 + 5 ;
int n,q;
string s[maxn][2],t[maxn][2];
map<pair<string,int>,string>mp[maxn];
map<string,int>cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=n;i++)
	{
		int len=s[i][1].size();
		int begin=0,end=len-1;
		for(int j=0;j<len;j++)	
			if(s[i][1][j]==s[i][2][j])
				begin=j;
			else	break ;
		for(int j=len-1;j>0;j--)
			if(s[i][1][j]==s[i][2][j])
				end=j;
			else	break ;
		string c,t;
		for(int j=begin;j<=end;j++)
			c+=s[i][1][j],t+=s[i][2][j];
		cnt[c]++;
		mp[c][cnt[c]]=t;
	}
	while(q--)
	{
		string c,t,c2,t2;
		cin>>c>>t;
		int len1=c.size();
		int len2=t.size();
		if(len1!=len2)	
		{
			cout<<0<<'\n';
			continue ;
		}
		int begin=0,end=len1-1;
		for(int i=0;i<len1;i++)
		{
			if(c[i]==t[i])
				begin=i;
			else	break ;
		}
		for(int i=len1-1;i>=0;i--)
		{
			if(c[i]==t[i])
				end=i;
			else	break ;
		}
		for(int i=begin;i<=end;i++)
			c2+=c[i],t2+=t[i];
		if(cnt[c2])
		{
			int ans=0;
			for(int i=1;i<=cnt[c2];i++)
				if(mp[c2][i]==t2)
					ans++;
			cout<<ans<<'\n';
		}
		else	cout<<0<<'\n';
	}
	return 0;
}
