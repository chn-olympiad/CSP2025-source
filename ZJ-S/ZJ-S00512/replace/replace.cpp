#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int p[N],q[N];
int ans=0;
string s1[N],s2[N];
void kmp(string s1,string s2,string t1,string t2)
{
	string g;
	int l=t1.size(),r=0;
	for(int i=0;i<t1.size();i++)
	{
		if(t1[i]!=t2[i])
		{
			l=min(l,i);
			r=max(l,i);
		}
	}
	//cout<<l<<' '<<r<<'\n';
	g=s1+'*'+t1;
	for(int i=1;i<g.size();i++)
	{
		int j=p[i-1];
		while(g[j]!=g[i]&&j!=0) j=p[j-1];
		if(g[j]==g[i]) j++;
		p[i]=j;
	}
	//cout<<s1<<' '<<s2;
	g=s2+'*'+t2;
	for(int i=1;i<g.size();i++)
	{
		int j=q[i-1];
		while(g[j]!=g[i]&&j!=0) j=q[j-1];
		if(g[j]==g[i]) j++;
		q[i]=j;
	}
	for(int i=s1.size()+1;i<g.size();i++)
	{
		//cout<<p[i]<<' '<<q[i]<<'\n';
		if(p[i]==q[i]&&p[i]==s1.size())
		{
			int id=i-s1.size()-1;
			if(id-s1.size()+1<=l&&id>=r) ans++;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;i++) kmp(s1[i],s2[i],t1,t2);
		cout<<ans<<'\n';
	}
	return 0;
}
