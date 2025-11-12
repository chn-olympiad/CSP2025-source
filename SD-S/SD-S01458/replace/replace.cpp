#include<bits/stdc++.h>
using namespace std;
map<string,int>vis;
map<string,string>mp;
int n,q;
string s1,s2,t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		vis[s1]=1;
		mp[s1]=s2;
	}
	while(q--)
	{
		cin>>t1>>t2;
		int len1,len2,ans=0;
		len1=t1.size(),len2=t2.size();
		t1=' '+t1;
		if(len1!=len2) {
			cout<<0<<'\n';
			continue;
		}
		int l=1e9,r=-1;
		for(int i=1;i<=len1;i++)
		if(t1[i]!=t2[i-1]) l=min(l,i),r=max(r,i);
		for(int i=l;i>=1;i--)
		{
			for(int j=r;j<=len1;j++)
			{
				string s=t1.substr(i,j-i+1);
				if(!vis[s]) continue;
				string ss=t1.substr(1,i-1);
				string sss=t1.substr(j+1,len1-(j+1)+1);
				if(ss+mp[s]+sss==t2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
