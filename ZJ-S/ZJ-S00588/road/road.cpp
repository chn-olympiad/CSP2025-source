#include <bits/stdc++.h>
#define ri register int
using namespace std;

inline long long read(){
	long long ret=0,f=1; char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c)) ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();
	return ret*f;
}

struct Edge{
	long long to,val,sub;
	const bool operator<(const Edge& x)const{return val<x.val;}
};

long long n,m,k,u,v,w,price[1000010],dis[10010],c[110],a[11][10010];
bitset<10010> vis;
bitset<1000010> b;
vector<Edge> e[10010];
priority_queue<Edge> q;

void dijkstra(long long root){
	vis.reset(),b.reset();
	for(ri i=0;i<10010;i++) dis[i]=1e9+7;
	dis[root]=0;
	Edge temp;
	temp.to=root,temp.val=0;
	q.push(temp);
	while(!q.empty()){
		Edge t=q.top();q.pop();
		long long u=t.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(ri i=0;i<e[u].size();i++){
			Edge ed=e[u][i];
			long long v=ed.to,w=ed.val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w,b[ed.sub]=1;
				temp.to=v,temp.val=dis[v];
				q.push(temp);
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n=read(),m=read(),k=read();
	for(ri i=0;i<m;i++){
		u=read(),v=read(),w=read();
		Edge temp;
		temp.to=v,temp.val=w,temp.sub=i;
		price[i]=w;
		e[u].push_back(temp);
		temp.to=u;
		e[v].push_back(temp);
	}
	if(k==0){
		long long ans=0x3f3f3f3f;
		for(ri i=1;i<=n;i++){
			dijkstra(i);
			long long sum=0;
			for(ri j=0;j<m;j++) if(b[j]) sum+=price[j];
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	else{
		bool flag=1;
		for(ri i=0;i<k;i++){
			c[i]=read();
			flag&=c[i]==0;
			for(ri j=1;j<=n;j++) a[i][j]=read();
		}
		if(flag){
			/*
			int aa[1010][1010];
			memset(aa,sizeof aa,0x3f);
			for(ri i=0;i<k;i++){
				for(ri j=1;j<=n;j++) for(ri l=j+1;l<=n;l++){
					Edge temp;
					temp.to=l,temp.val=a[i][j]+a[i][l],temp.sub=m++;
					aa[j][l]=min(aa[j][l],(int)(a[i][j]+a[i][l]));
				}
			}
			for(ri j=1;j<=n;j++) for(ri l=j+1;l<=n;l++){
				Edge temp;
				temp.to=l,temp.val=aa[j][l],temp.sub=m++;
				e[j].push_back(temp);
				temp.to=j,temp.sub=m++;
				e[l].push_back(temp);
			}
			
			long long ans=0x3f3f3f3f;
			for(ri i=1;i<=n;i++){
				dijkstra(i);
				long long sum=0;
				for(ri j=0;j<m;j++) if(b[j]) sum+=price[j];
				ans=min(ans,sum);
			}
			printf("%lld\n",ans);*/
		}
	}

	return 0;
}/*
3 2 0
1 2 3
2 3 3

4 4 0
1 2 4
2 3 3
3 4 5
1 4 1
*/
