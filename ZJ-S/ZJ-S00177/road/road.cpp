#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
#define int long long
long long ans=LLONG_MAX;
int a,b,c;
int cnt=1;
long long tot=0;
int n,m,k;
int fa[10001];
int vis[11];
int cost[11];
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int aa=find(a),bb=find(b);
	fa[aa]=bb;
}
long long maximum=0;
struct node{
	int u,v;long long w; int s=0;
	bool operator<(const node a)const{
		return w>a.w;
	}
}T;
priority_queue<node>q;
priority_queue<node>tr;
node t[maxn];
void solve(){
	long long res=0;
	for(int i=1;i<=k;i++)if(vis[i])res+=cost[i];
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=tot;i++){
		if(t[i].s>0&&!vis[t[i].s])continue;
		if(find(t[i].u)==find(t[i].v))continue;
		res+=t[i].w;  
		merge(t[i].u,t[i].v);
	}
	ans=min(ans,res);
	return;
}
void dfs(int x){
	if(x==k+1){
		solve();
	}
	else{
		vis[x]=0; dfs(x+1);
		vis[x]=1; dfs(x+1);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		T.u=read(); T.v=read(); T.w=read(); q.push(T);
	}
	while(!q.empty()&&cnt<n){
		node W=q.top(); q.pop();
		if(find(W.u)==find(W.v))continue;
		maximum=max(maximum,W.w); W.s=0;
		merge(W.u,W.v); cnt++;
		tr.push(W); 
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=k;i++){
		cost[i]=read();
		for(int j=1;j<=n;j++){
			c=read();
			T.u=n+i; T.v=j; T.w=c; T.s=i;
			if(c>maximum)continue;
			tr.push(T);
		}
	}	
	while(!tr.empty())t[++tot]=tr.top(),tr.pop();
	dfs(1);
	write(ans); cout<<'\n';
	return 0;
}