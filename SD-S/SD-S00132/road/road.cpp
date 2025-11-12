#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+10,M=1e5+10;

int n,m,k;
int f[N];
int op[15];
struct node{
	ll u,v,w;
}e[N];
int t;
ll ans;
int read(){
	char c;
	int f=1,x=0;
	c=getchar();
	if(c=='-')f=-1;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void add(int a,int b,int c){
	e[++t].u=a;
	e[t].v=b;
	e[t].w=c;
}
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int vis[N];
bool check(){
	for(int i=1;i<=n;i++){
		if(!vis[i])return 0;
	}
	return 1;
}
queue<int> q;
void kruskal(){
	for(int i=1;i<=n+k;i++)f[i]=i;
	sort(e+1,e+1+t,cmp);
	for(int i=1;i<=t;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y)continue;
		ans+=e[i].w;
		f[x]=y;
		vis[e[i].u]=1;
		vis[e[i].v]=1;
		q.push(i);
		if(check())break;
	}
}
/*
void dijsktra(){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,1});
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				q.push({dis[v],v});
			}
		}
	}
}
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		int w;
		op[i]=read();
		for(int j=1;j<=n;j++){
			w=read();
			add(n+i,j,w+op[i]);
		}
	}
	kruskal();
	while(!q.empty()){
		int i=q.front();
		q.pop();
		if(e[i].u>n)vis[e[i].u]++;
		else if(e[i].v>n)vis[e[i].v]++; 
	}
	for(int i=1;i<=k;i++){
		if(vis[n+i]){
			ans-=(op[i]*vis[n+i]-2);
		}
	}
	printf("%d\n",ans);
	return 0;
}

