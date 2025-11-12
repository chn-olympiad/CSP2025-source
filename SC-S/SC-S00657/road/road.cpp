#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair

const int N=2e4+3,K=13,M=2e6+3;
const ll inf=0x3f3f3f3f3f3f3f3f;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

using namespace std;

int n,m,k;
ll ans=inf;
int a[K][N],c[K];
bool chose[K];
struct node{
	int u,v,w;
	friend bool operator >(node a,node b){return a.w>b.w;}
};

priority_queue<node,vector<node>,greater<node> > e,ee;

int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool cmp(node A,node B){return A.w<B.w;}

void kruskal(){
	ll res=0;
	int idx=n,cnt=0;
	e=ee;
	for(int i=1;i<=k;++i){
		if(!chose[i]) continue;
		res+=c[i];idx++;
		for(int u=1;u<=n;++u) e.push({idx,u,a[i][u]});
	}
	for(int i=1;i<=idx;++i) fa[i]=i;
	while(!e.empty()){
		auto now=e.top();e.pop();
		int fu=find(now.u),fv=find(now.v);
		if(fu==fv) continue;
		fa[fu]=fv;res+=now.w;
		if(++cnt==idx-1) break;
	}
	ans=min(ans,res);
}

void dfs(int p){
	if(p>k) return kruskal();
	for(int i=0;i<=1;++i) chose[p]=i,dfs(p+1);
}

signed main(){
//	system("fc road.out road4.ans");exit(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		ee.push({u,v,w});
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)
			a[i][j]=read();
	}
	int cnt=0,res=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	while(!ee.empty()){
		auto now=ee.top();ee.pop();
		int fu=find(now.u),fv=find(now.v);
		if(fu==fv) continue;
		fa[fu]=fv;res+=now.w;
		e.push(now);
		if(++cnt==n-1) break;
	}
	if(k==0) return cout<<res<<'\n',0;
	ee=e;m=n-1;dfs(1);
	cout<<ans<<'\n';
	return 0;
}