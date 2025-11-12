#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=2e6;
//bool X1;
int n,m,k;
struct node{
	int u,v,w,nxt;
}mp[N],mp2[N],E[N];
int top;
int idx[N];
int idxe[N];
int tope;
int idx2[N];
void AD(int u,int v,int w){
	E[++tope].u=u;
	E[tope].v=v;
	E[tope].w=w;
	E[tope].nxt=idxe[u];
	return;
}
void add(int u,int v,int w){
	mp[++top].u=u;
	mp[top].v=v;
	mp[top].w=w;
	mp[top].nxt=idx[u];
	idx[u]=top;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int a[N][14];
int c[N];
int cnt;
vector<int>g;
long long ans;
int f[N];
int root(int x){
	if(f[x]==x)return x;
	return f[x]=root(f[x]);
}
void Add(int u,int v,int w){
	mp2[++top].u=u;
	mp2[top].v=v;
	mp2[top].w=w;
	mp2[top].nxt=idx2[u];
}
void cal(){
	int cnt=n+1;
	long long sum=0;
	for(int i=1;i<=top;i++)mp2[i]=mp[i];
	int u=top;
	for(int i=1;i<=n;i++)idx2[i]=idx[i];
	for(int i=0;i<g.size();i++){
		cnt++;
		if(g[i]==0)continue;
		sum+=c[i+1];
		for(int j=1;j<=n;j++)Add(cnt,j,a[j][i+1]);
	}
	for(int i=1;i<=cnt;i++)f[i]=i;
	sort(mp2+1,mp2+1+top,cmp);
	int sm=0;
	for(int i=1;i<=top;i++){
		if(root(mp2[i].u)==root(mp2[i].v))continue;
		sum+=mp2[i].w;
		f[root(mp2[i].u)]=root(mp2[i].v);
		sm++;
		if(sm==cnt-1)break;
	}	
	ans=min(ans,sum);
	top=u;
	return;
}
void dfs(int u){
	if(u==k+1){
		cal();
		return;
	}
	g.push_back(1);
	dfs(u+1);
	g.pop_back();
	g.push_back(0);
	dfs(u+1);
	g.pop_back();
	return; 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(mp+1,mp+1+top,cmp);
	int s=0;
	for(int i=1;i<=top;i++){
		if(root(mp[i].u)==root(mp[i].v))continue;
		ans+=mp[i].w;
		f[root(mp[i].u)]=root(mp[i].v);
		AD(mp[i].u,mp[i].v,mp[i].w);
		s++;
		if(s==n-1)break;
	}
	top=tope;
	for(int i=1;i<=n;i++)idx[i]=idxe[i];
	for(int i=1;i<=top;i++)mp[i]=E[i];
	cnt=n+1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[j][i]=read();
	}
	dfs(1);
	cout<<ans<<"\n";
//	bool Y1;
//	cout<<abs(&X1-&Y1)*1.0/1024.0/1024.0<<"\n";
	return 0;
}
//½èÇ«¸çÖ®Á¦AC

