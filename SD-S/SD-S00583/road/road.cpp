#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+10;
const int M=1e3+10;
const ll INF=1e18;
int n,m,k,id,fa[N],id2;
bool checkA=1;
ll ans,dis[M][M],d[M][20],cost[20];
struct node{
	int from,to;
	ll len;
}a[N],b[N];
void add(int u,int v,ll l){
	id++;
	a[id].from=u;
	a[id].to=v;
	a[id].len=l;
}
void add2(int u,int v,ll l){
	id2++;
	b[id2].from=u;
	b[id2].to=v;
	b[id2].len=l;
}
bool cmp(node n1,node n2){
	return n1.len<n2.len;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
void solve1(){
	int cnt=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].from)!=find(a[i].to)){
			merge(a[i].from,a[i].to);
			ans+=a[i].len;cnt++;
		}
		if(cnt==n-1){
			printf("%lld\n",ans);
			return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
	if(n<=1000){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				dis[i][j]=dis[j][i]=INF;
			}
			dis[i][i]=0;
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
    	int x,y;
		ll l;
    	scanf("%d%d%lld",&x,&y,&l);
    	if(n<=1000){
    		dis[x][y]=dis[y][x]=min(dis[x][y],l);
		}
    	add(x,y,l);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cost[i]);
		if(cost[i]>0)checkA=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[j][i]);
		}
	}
	if(k==0){solve1();return 0;}
	if(checkA&&n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=1;q<=k;q++){
					if(dis[i][j]==INF)dis[i][j]=dis[j][i]=d[i][q]+d[j][q];
					else dis[j][i]=dis[i][j]=min(dis[i][j],d[i][q]+d[j][q]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				add2(i,j,dis[i][j]);
			}
		}
		sort(b+1,b+id2+1,cmp);
		int cnt=0;
		for(int i=1;i<=id2;i++){
    		if(find(b[i].from)!=find(b[i].to)){
	    		merge(b[i].from,b[i].to);
	    		ans+=b[i].len;cnt++;
    		}
			if(cnt==n-1){
	    		printf("%lld\n",ans);
	      		return 0;
	    	}
    	}
    }
	return 0;
}

