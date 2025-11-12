#include<bits/stdc++.h>
#include<ctime>
using namespace std;
#define ll long long
int read(){
	int outt=0;
	char gett=getchar();
	while(gett<'0' || gett>'9')gett=getchar();
	while(gett>='0' && gett<='9')outt*=10,outt+=gett-'0',gett=getchar();
	return outt;
}
int n,m,k; 
struct node{
	int to;
	ll s;
};
vector<node> mp[10011];
bool operator<(node a,node b){
	return a.s>b.s;
}
priority_queue<node> qu;
int a[11];
bool bu[11];
ll dis[10011];
bool vis[10011];
int rd[2049];
int main(){
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		a[i]=read();
		for(int j=1;j<=n;j++){
			int w;
			w=read();
			mp[i+n].push_back({j,w});
			mp[j].push_back({i+n,w});
		}
	}
	ll ans=LONG_LONG_MAX;
	int bitmax=(1<<k)-1;
	for(int i=0;i<=bitmax;i++)rd[i]=i;
	for(int i=1;i<=bitmax;i++){
		swap(rd[i],rd[rand()%i]);
	}
	int c=clock();
	for(int b=0,i=rd[0];b<=bitmax;b++,i=rd[b]){
		ll la=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i)bu[j]=1,la+=a[j];
			else bu[j]=0;
		}
		memset(vis,0,sizeof(bool)*(n+k+1));
		memset(dis,0x3f,sizeof(ll)*(n+k+1));
		dis[1]=0;
		qu.push({1,0});
		while(qu.size()){
			node x=qu.top();
			qu.pop();
			if(vis[x.to]||la>=ans)continue;
			vis[x.to]=1;
			la+=x.s;
			for(node u:mp[x.to]){
				if(vis[u.to])continue;
				if(u.to>n && !bu[u.to-n])continue;
				if(u.s<dis[u.to]){
					dis[u.to]=u.s;
					qu.push({u.to,dis[u.to]});
				}
			}
		}ans=min(ans,la);
		if((clock()-(double)c)/CLOCKS_PER_SEC>0.9)break;
	}printf("%lld",ans);
	return 0;
} 
