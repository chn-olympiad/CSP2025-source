#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,Q=2e5+5;
const char ept='{';
int idx,n,m,head[N],cnt,num[N],ans[Q];
string s2,e[Q],f[Q];
struct trie
{
	int son[28],cnt,fail;
}s[N];
map<string,vector<int> > q,d; 
struct edge
{
	int v,nxt;
}a[N];
void add(int u,int v)
{
	a[++cnt].v=v;
	a[cnt].nxt=head[u];
	head[u]=cnt;
}
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void insert(string &a)
{
	int u=0;
	for(int i=0;i<a.size();i++)
	{
		int w=a[i]-'a';
		if(!s[u].son[w]) s[u].son[w]=++idx;
		u=s[u].son[w];
	}
	s[u].cnt++;
}
void get_fail()
{
	queue<int> q;
	for(int i=0;i<27;i++) if(s[0].son[i]) q.push(s[0].son[i]),add(0,s[0].son[i]);
	while(!q.empty()) 
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<27;i++)
		{
			if(s[u].son[i])
			{
				s[s[u].son[i]].fail=s[s[u].fail].son[i];
				add(s[s[u].fail].son[i],s[u].son[i]);
				q.push(s[u].son[i]);
			}
			else s[u].son[i]=s[s[u].fail].son[i];
		}
	}
}
void dfs(int u)
{
	num[u]+=s[u].cnt;
	for(int i=head[u];i!=0;i=a[i].nxt)
	{
		int v=a[i].v;
		num[v]+=num[u];
		dfs(v);
	}
}
void init()
{
	for(int i=0;i<=idx;i++) 
	{
		head[i]=s[i].cnt=s[i].fail=num[i]=0;
		for(int j=0;j<27;j++) s[i].son[j]=0;
	}
	cnt=idx=0;
}
int query(string &op)
{
	int res=0,u=0;
	for(int i=0;i<op.size();i++)
	{
		int w=op[i]-'a';
		u=s[u].son[w];
		res+=num[u];
	}
	return res;
}
void solve(string op)
{
	if(!q[op].size()) return;
	init();
	for(auto x:d[op]) insert(e[x]);
	get_fail();
	dfs(0);
	for(auto x:q[op]) ans[x]=query(f[x]);
}
void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>e[i]>>s2;
		string l="";
		for(int j=0;j<e[i].size();j++) 
		{
			if(e[i][j]!=s2[j]) l+=e[i][j],l+=s2[j],e[i][j]=ept;
		}
		d[l].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>f[i]>>s2;
		string l="";
		for(int j=0;j<f[i].size();j++) 
		{
			if(f[i][j]!=s2[j]) l+=f[i][j],l+=s2[j],f[i][j]=ept;
		}
		if(d[l].size()) q[l].push_back(i);
	}
	
	for(auto x:d) solve(x.first);
	for(int i=1;i<=m;i++) write(ans[i]),putchar('\n');
	return 0;
}
