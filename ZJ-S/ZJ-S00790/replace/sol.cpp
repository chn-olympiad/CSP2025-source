#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5,T=1.1e7,S=26,B=1301,mod[]{int(1e9+7),int(1e9+9)};
struct dat{int x,y,z,op;}A[N*3];
int ps[N][2],pt[N][2],ans[N],bit[M],tr[T][S],dfn[T],siz[T],tot;
vector<int>v1[N<<1],v2[N<<1];
string s[N][2],t[N][2],t1,t2;
ll vs[N],vt[N],dst[N<<1];
void add(int x,int k){for(;x<M;x+=x&-x)bit[x]+=k;}
int ask(int x){int res=0;for(;x;x-=x&-x)res+=bit[x];return res;}
void dfs(int u)
{
	dfn[u]=++dfn[0],siz[u]=1;
	for(int c=0;c<S;++c)if(tr[u][c])dfs(tr[u][c]),siz[u]+=siz[tr[u][c]];
}
void solve(vector<int>&v1,vector<int>&v2)
{
	int rt[2],l1=v1.size(),l2=v2.size();rt[0]=++tot,rt[1]=++tot;
	for(int i=0;i<l1;++i)for(int o:{0,1})
	{
		int x=v1[i],p=rt[o];
		for(int j=0,len=s[x][o].size();j<len;++j)
		{
			int &q=tr[p][s[x][o][j]-'a'];
			p=q?q:q=++tot;
		}
		ps[i][o]=p;
	}
	for(int i=0;i<l2;++i)for(int o:{0,1})
	{
		int x=v2[i],p=rt[o];
		for(int j=0,len=t[x][o].size();j<len;++j)
		{
			int &q=tr[p][t[x][o][j]-'a'];
			p=q?q:q=++tot;
		}
		pt[i][o]=p;
	}
	dfn[0]=0,dfs(rt[0]),dfn[0]=0,dfs(rt[1]);
	int tot=0;
	for(int i=0;i<l1;++i)
	{
		A[++tot]={dfn[ps[i][0]],dfn[ps[i][1]],dfn[ps[i][1]]+siz[ps[i][1]],1};
		A[++tot]={dfn[ps[i][0]]+siz[ps[i][0]],dfn[ps[i][1]],dfn[ps[i][1]]+siz[ps[i][1]],-1};
	}
	for(int i=0;i<l2;++i)A[++tot]={dfn[pt[i][0]],dfn[pt[i][1]],v2[i],0};
	sort(A+1,A+tot+1,[=](dat x,dat y){return x.x<y.x||x.x==y.x&&abs(x.op)>abs(y.op);});
	for(int i=1;i<=tot;++i)
		if(A[i].op)add(A[i].y,A[i].op),add(A[i].z,-A[i].op);
		else ans[A[i].z]+=ask(A[i].y);
	for(int i=1;i<=tot;++i)if(A[i].op)add(A[i].y,-A[i].op),add(A[i].z,A[i].op);
}
void ATRI()
{
	int n,m;cin>>n>>m;int cnt=0;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][0]>>s[i][1];int len=s[i][0].size(),fl=1;
		for(int j=0;j<len;++j)fl&=s[i][0][j]==s[i][1][j];
		if(fl)continue;
		int p=0,q=len-1,ps=0;
		while(s[i][0][p]==s[i][1][p])++p;
		while(s[i][0][q]==s[i][1][q])--q;
		int h[2]{0,0};
		for(int k:{0,1})for(int j=p;j<=q;++j)for(int o:{0,1})
			h[k]=(1ll*h[k]*B+s[i][o][j])%mod[k];
		dst[++cnt]=vs[i]=1ll*h[0]*h[1];
		t1=t2="";
		for(int j=p-1;~j;--j)t1+=s[i][0][j];
		for(int j=q+1;j<len;++j)t2+=s[i][1][j];
		s[i][0]=t1,s[i][1]=t2;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>t[i][0]>>t[i][1];int len=t[i][0].size();
		int p=0,q=len-1,ps=0;
		while(t[i][0][p]==t[i][1][p])++p;
		while(t[i][0][q]==t[i][1][q])--q;
		int h[2]{0,0};
		for(int k:{0,1})for(int j=p;j<=q;++j)for(int o:{0,1})
			h[k]=(1ll*h[k]*B+t[i][o][j])%mod[k];
		dst[++cnt]=vt[i]=1ll*h[0]*h[1];
		t1=t2="";
		for(int j=p-1;~j;--j)t1+=t[i][0][j];
		for(int j=q+1;j<len;++j)t2+=t[i][1][j];
		t[i][0]=t1,t[i][1]=t2;
	}
	sort(dst+1,dst+cnt+1),cnt=unique(dst+1,dst+cnt+1)-dst-1;
	for(int i=1;i<=n;++i)v1[lower_bound(dst+1,dst+cnt+1,vs[i])-dst].push_back(i);
	for(int i=1;i<=m;++i)v2[lower_bound(dst+1,dst+cnt+1,vt[i])-dst].push_back(i);
	for(int i=1;i<=cnt;++i)if(v1[i].size()&&v2[i].size())solve(v1[i],v2[i]);
	for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ATRI();
	return 0;
}