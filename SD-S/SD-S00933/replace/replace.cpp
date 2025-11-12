#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
//char t[N][2*N],s[N][2*N],t0[N*2],s0[N*2];
string t[N],s[N],dt0,ds0;
int p[2*N],ans;
void kmp(int n,int m,string t,string s,string t1,string s0,string s1)
{
	memset(p,0,sizeof p);
	for(int i=2,j=0;i<=n;++i)
	{
		while(j && t[j+1]!=t[i])j=p[j];
		if(t[j+1]==t[i])j++;
		p[i]=j;
	}
	for(int i=1,j=0;i<=m;++i)
	{
		while(j && t[j+1]!=s[i])j=p[j];
		if(t[j+1]==s[i])j++;
		if(j==n)
		{
			string l=t1.substr(0,i-n),r=t1.substr(i,m-i);
			string newstr=l+s0+r;
			if(newstr==s1)ans++;
			j=p[j];
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		string tx,sx;
		cin>>t[i]>>s[i];
	}
	while(m--)
	{
		ans=0;
		cin>>dt0>>ds0;
		for(int i=1;i<=n;++i)
			kmp(t[i].size(),dt0.size()," "+t[i]," "+dt0,dt0,s[i],ds0);
		cout<<ans<<"\n";
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
