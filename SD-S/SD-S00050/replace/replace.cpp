#include<bits/stdc++.h>
using namespace std;
const int mx=2e5;
const int nx=5e6;
bool ff[mx+10];
char a[nx+10],b[nx+10];
char s[nx+10],t[nx+10];
int st[mx+10],idx=1;
map<int,int> ch[nx+10];
int lenn[nx+10];
queue<int> q;
int fl[nx+10],fth[nx+10][23],num[nx+10];
void bldac()
{
	int i,j,u,v,x;
	for(auto it=ch[1].begin();it!=ch[1].end();++it)
		{q.push(it->second);fl[it->second]=1;}
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(auto it=ch[u].begin();it!=ch[u].end();++it)
		{
			j=it->first;v=it->second;x=fl[u];
			while(x&&ch[x].count(j)==0) x=fl[x];
			if(!x) fl[v]=1;
			else fl[v]=ch[x][j];
			num[v]+=num[fl[v]];
			fth[v][0]=fl[v];
			for(i=1;i<=22;++i)
				fth[v][i]=fth[fth[v][i-1]][i-1];
			q.push(v);
		}
	}
	return;
}
int getn(int u,int ky)
{
	int i;
	for(i=22;i>=0;--i)
		if(lenn[fth[u][i]]>=ky)
			u=fth[u][i];
	return u;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j,n,m,u,lt,rg;
	long long ans=0;
	scanf("%d%d",&n,&m);
	lenn[0]=-1;
	for(i=1;i<=n;++i)
	{
		scanf("%s%s",a+1,b+1);
		u=1;
		for(j=1;a[j]!='\0';++j)
		{
			if(ch[u].count((a[j]-'a')*26+(b[j]-'a'))==0)
			{
				ch[u][(a[j]-'a')*26+(b[j]-'a')]=++idx;
				lenn[idx]=lenn[u]+1;
			}
			u=ch[u][(a[j]-'a')*26+(b[j]-'a')];
		}
		++num[u];
	}
	for(i=1;i<=m;++i)
	{
		scanf("%s%s",s+st[i-1]+1,t+st[i-1]+1);
		if(strlen(s+st[i-1]+1)!=strlen(t+st[i-1]+1))
			{ff[i]=true;st[i]=st[i-1];}
		else
		{
			st[i]=st[i-1]+strlen(s+st[i-1]+1);
			u=1;
			for(j=st[i-1]+1;j<=st[i];++j)
			{
				if(ch[u].count((s[j]-'a')*26+(t[j]-'a'))==0)
				{
					ch[u][(s[j]-'a')*26+(t[j]-'a')]=++idx;
					lenn[idx]=lenn[u]+1;
				}
				u=ch[u][(s[j]-'a')*26+(t[j]-'a')];
			}
		}
	}
	bldac();
	for(i=1;i<=m;++i)
		if(ff[i]) puts("0");
		else
		{
			lt=1e9;rg=-1e9;
			for(j=st[i-1]+1;j<=st[i];++j)
				if(s[j]!=t[j])
				{
					lt=min(lt,j);
					rg=max(rg,j);
				}
			u=1;ans=0;
			for(j=st[i-1]+1;j<=rg;++j)
				u=ch[u][(s[j]-'a')*26+(t[j]-'a')];
			ans+=num[u]-num[fl[getn(u,rg-lt+1)]];
			for(j=rg+1;j<=st[i];++j)
			{
				u=ch[u][(s[j]-'a')*26+(t[j]-'a')];
				ans+=num[u]-num[fl[getn(u,j-lt+1)]];
			}
			printf("%lld\n",ans);
		}
	return 0;
}
