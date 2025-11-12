#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,m,k,dis[10025],c[20],pd[20],F,pd1,d[10025];
bool vis[10025];
struct node{
	int v,w;
};
vector<node> vt[10025];
priority_queue<pair<int,int>> q;
int prim(){
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n+k;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	int ans=0;int S=0;
	q.push({0,1});dis[1]=0;
	while(!q.empty()){
		int u=q.top().second,w=q.top().first;
		q.pop();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		ans+=-w;
		if(u<=n){
			S++;
			if(S==n){
				break;
			}
		}
		for(int i=0;i<vt[u].size();i++){
			int v=vt[u][i].v,w=vt[u][i].w;
			if(vis[v]==1){
				continue;
			}
			if(v>n&&pd[v-n]==1){
				continue;
			}
			if(w<dis[v]){
				dis[v]=w;
				q.push({-dis[v],v});
			}
		}
	}
	return ans;
}
priority_queue<pair<int,pair<int,int>>> qp;
int prim1(){
	while(!qp.empty()){
		qp.pop();
	}
	for(int i=1;i<=n+k;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	int ans=0;int S=0;
	//cout<<1<<'\n';
	qp.push({0,{1,0}});dis[1]=0;
	while(!qp.empty()){
		int u=qp.top().second.first,w=qp.top().first;
		int fr=qp.top().second.second;
		qp.pop();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		ans+=-w;
		d[fr]++;
		d[u]++;
		//	cout<<fr<<" "<<u<<'\n';
		if(u<=n){
			S++;
			if(S==n){
				break;
			}
		}
		for(int i=0;i<vt[u].size();i++){
			int v=vt[u][i].v,w=vt[u][i].w;
			if(vis[v]==1){
				continue;
			}
			if(v>n){
				if(w+c[v-n]<dis[v]){
					dis[v]=w+c[v-n];
					qp.push({-dis[v],{v,u}});
				}
			}else {
				if(w<dis[v]){
					dis[v]=w;
					qp.push({-dis[v],{v,u}});
				}
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		vt[u].push_back({v,w});
		vt[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0){
			pd1=1;
		}
		for(int j=1;j<=n;j++){
			int w;
			w=read();
			vt[i+n].push_back({j,w});
			vt[j].push_back({i+n,w});
		}
	}
	if(pd1==0){
		int ans=prim();
		write(ans);
		return 0;
	}else if((k<=5&&n<=1000&&m<=100000)||(k==0)){
		int ans=1e18;
		for(int i=0;i<=(1<<k)-1;i++){
			for(int j=1;j<=k;j++){
				pd[i]=0;
			}
			int sum=0;
			for(int j=1;j<=k;j++){
				if(((1<<(j-1))&i)==0){
					pd[j]=1;
				}else{
					sum+=c[j];
				}
			}
			int s=prim();
			//cout<<i<<" "<<s<<" "<<sum<<'\n';
			ans=min(ans,s+sum);
		}
		write(ans);
	}else{
		int ans=prim1();
		for(int i=n+1;i<=n+k;i++){
			cout<<d[i]<<'\n';
			if(d[i]==1){
				//cout<<1<<'\n';
				ans-=c[i-n];
			}
		}
		write(ans);
	}
	return 0;
}//算法思路：最小生成树prim 52pts~100pts