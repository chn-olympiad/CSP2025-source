#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL inf=1e16;
int n,m,k,vis[10055],c[15],f[10005],ch[15];
LL ans,val[10055];
struct Node{
	int u,v,w;
	bool friend operator<(Node a,Node b){
		return a.w>b.w;
	}
}e[1000005];
vector<Node>mp[10055];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
inline int read(){
	char ch=getchar();
	int u=0;
	while(ch>='0'&&ch<='9'){u=u*10+ch-'0';ch=getchar();}
	return u;
}
inline void get(LL t){
	LL sum=0;
	priority_queue<Node>q;
	int nn=n+k;
	for(register int i=2;i<=nn;i++){
		vis[i]=0;
		val[i]=inf;
	}
	vis[1]=1;
	int bg=mp[1].size();
	for(register int i=0;i<bg;i++){
		int v=mp[1][i].v;
		if(v<=n||ch[v-n]){
			val[v]=mp[1][i].w;
			q.push((Node){0,v,mp[1][i].w});
		}
	}
	while(!q.empty()){
		Node a=q.top();
		q.pop();
		int x=a.v;
		if(vis[x])continue;
		sum+=a.w;
		if(sum+t>=ans)return;
		vis[x]=1;
		bg=mp[x].size();
		for(int i=0;i<bg;i++){
			int v=mp[x][i].v;
		    if(val[v]>mp[x][i].w&&(v<=n||ch[v-n])){
			    val[v]=mp[x][i].w;
			    q.push((Node){0,v,mp[x][i].w});
		    }
		}
	}
	if(ans>sum+t)ans=sum+t;
}
void dfs(int x,LL sum,int s){
	if(sum>=ans)return;
	if(x==k+1){
		if(!s)return;
		get(sum);
		return;
	}
	dfs(x+1,sum,s);
	ch[x]=1;
	dfs(x+1,sum+c[x],1);
	ch[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(register int i=1;i<=n;i++)f[i]=i;
	for(register int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+1+m);
	LL sum=0,num=0;
	for(register int i=m;i>=1;i--){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			num++;
			sum+=e[i].w;
			mp[e[i].u].push_back((Node){0,e[i].v,e[i].w});
			mp[e[i].v].push_back((Node){0,e[i].u,e[i].w});
			f[fx]=fy;
			if(num==n-1)break;
		}
	}
	ans=sum;
	for(register int i=1;i<=k;i++){
		c[i]=read();
		for(register int j=1;j<=n;j++){
			int u;
			u=read();
			mp[j].push_back((Node){0,i+n,u});
			mp[i+n].push_back((Node){0,j,u});
		}
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
