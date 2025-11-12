//李倏嘉 SN-S00323 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2.5e6+5,K=26;
const long long Mod=1e15+37;
int n,m,q,cnt,l[N<<1],r[N<<1],ans[N],id1[N],id2[N],c[M],cnt0,cnt1,rt0,rt1,tr1[M][K],tr2[M][K],dfn1[M],dfn2[M],siz1[M],siz2[M],p=1331;
string s[N],t[N],a[N],b[N];
map< pair<long long,long long>,int >mp;
vector<int>v[N],w[N];
struct node{
	int l,r,x;
};
basic_string<int>v1[M],v2[M],vv[M];
basic_string<node>ww[M];
void dfs1(int x)
{
	dfn1[x]=++cnt0,siz1[x]=1;
	for(auto y:v1[x])dfs1(y),siz1[x]+=siz1[y];
}
void dfs2(int x)
{
	dfn2[x]=++cnt1,siz2[x]=1;
	for(auto y:v2[x])dfs2(y),siz2[x]+=siz2[y];
}
void ins(int x,int y,int u,int v)
{
	ww[x]+={u,v,1},ww[y+1]+={u,v,-1};
}
void add(int x,int y)
{
	for(int i=x;i<=cnt1;i+=i&-i)c[i]+=y;
}
int ask(int x)
{
	int ret=0;
	for(int i=x;i;i-=i&-i)ret+=c[i];
	return ret;
}
void read(string &s)
{
	char c;
	while(1)
	{
		c=getchar();
		if(c>='a'&&c<='z')break;
	}
	s+=c;
	while(1)
	{
		c=getchar();
		if(c<'a'||c>'z')break;
		s+=c;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		read(s[i]),read(t[i]);
		if(s[i]==t[i])continue;
		l[i]=0,r[i]=s[i].size()-1;
		while(s[i][l[i]]==t[i][l[i]])l[i]++;
		while(s[i][r[i]]==t[i][r[i]])r[i]--;
		long long val0=0,val1=0;
		for(int j=l[i];j<=r[i];j++)val0=(val0*p+s[i][j])%Mod,val1=(val1*p+t[i][j])%Mod;
		if(!mp[{val0,val1}])mp[{val0,val1}]=++cnt,v[cnt].push_back(i);
		else v[mp[{val0,val1}]].push_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		read(a[i]),read(b[i]);
		l[i+n]=0,r[i+n]=a[i].size()-1;
		while(a[i][l[i+n]]==b[i][l[i+n]])l[i+n]++;
		while(a[i][r[i+n]]==b[i][r[i+n]])r[i+n]--;
		long long val0=0,val1=0;
		for(int j=l[i+n];j<=r[i+n];j++)val0=(val0*p+a[i][j])%Mod,val1=(val1*p+b[i][j])%Mod;
		w[mp[{val0,val1}]].push_back(i);
	}
	for(int i=1;i<=cnt;i++)
	{
		if(!w[i].size())continue;
		cnt0=cnt1=0;
		for(auto x:w[i])
		{
			int p=0,now=l[x+n]-1;
			while(now>=0)
			{
				int c=a[x][now]-'a';
				if(!tr1[p][c])tr1[p][c]=++cnt0,v1[p]+=cnt0;
				p=tr1[p][c],now--;
			}
			id1[x]=p,p=0;
			now=r[x+n]+1;
			while(now<a[x].size())
			{
				int c=a[x][now]-'a';
				if(!tr2[p][c])tr2[p][c]=++cnt1,v2[p]+=cnt1;
				p=tr2[p][c],now++;
			}
			id2[x]=p;
		}
		cnt0=cnt1=0,dfs1(0),dfs2(0);
		for(auto x:v[i])
		{
			int p=0,q=0,now=l[x]-1,flag=0;
			while(now>=0)
			{
				int c=s[x][now]-'a';
				p=tr1[p][c],now--;
				if(!p)
				{
					flag=1;
					break;
				}
			}
			now=r[x]+1;
			while(now<s[x].size())
			{
				int c=s[x][now]-'a';
				q=tr2[q][c],now++;
				if(!q)
				{
					flag=1;
					break;
				}
			}
			if(flag)continue;
			ins(dfn1[p],dfn1[p]+siz1[p]-1,dfn2[q],dfn2[q]+siz2[q]-1);
		}
		for(auto x:w[i])vv[dfn1[id1[x]]]+=x;
		for(int j=1;j<=cnt0+1;j++)
		{
			for(auto x:ww[j])add(x.l,x.x),add(x.r+1,-x.x);
			for(auto x:vv[j])ans[x]=ask(dfn2[id2[x]]);
		}
		for(int j=0;j<=cnt0+1;j++)ww[j].clear(),vv[j].clear(),memset(tr1[j],0,sizeof(tr1[j])),v1[j].clear();
		for(int j=0;j<=cnt1+1;j++)memset(tr2[j],0,sizeof(tr2[j])),v2[j].clear();
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

