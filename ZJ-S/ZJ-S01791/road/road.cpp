#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+50,M=1e6+10;
int n,m,k,a[12][N],c[12],fa[N],sz[N];
struct node{
	int x,y,w;
}e[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
vector<node>D,E;
//pair<int,int>Q[12];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
ll ans=1e18;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	}
	for(int i=1;i<=m;++i){
		E.push_back(e[i]);
	}
	for(int i=0;i<k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			E.push_back({n+i+1,j,a[i][j]});
		}
	}
	sort(E.begin(),E.end(),cmp);
//	for(auto i:E){
//		int x=i.x;
//		if(x>n){
//			Q[x-n-1].push_back({i.y,i.w});
//		}
//	}
	for(int i=0;i<(1<<k);++i){
		int geshu=0;
		for(int j=1;j<=n+k+1;++j){
			fa[j]=j,sz[j]=1;
		}
		ll res=0;
		for(int j=0;j<k;++j){
			if(i&(1<<j)){
				geshu++,res+=c[j];
//				for(int l=1;l<=n;++l){
//					F.push_back({n+j+1,l,a[j][l]});
//				}
			}
		}
		vector<node>F;
		for(auto j:E){
			int x=j.x;
			if(x>n){
				if(i&(1<<x-n-1)){
					F.push_back({x,j.y,j.w});
				}
			}
			else{
				F.push_back(j);
			}
		}
//		sort(F.begin(),F.end(),cmp);
		int cnt=0;
		for(auto j:F){
			if(cnt==n+geshu-1){
				break;
			}
			int x=j.x,y=j.y,w=j.w;
			x=find(x),y=find(y);
			if(x==y){
				continue;
			}
			cnt++,res+=w;
			if(sz[x]<sz[y]){
				sz[y]+=sz[x],sz[x]=0;
				fa[x]=y;
			}
			else{
				sz[x]+=sz[y],sz[y]=0;
				fa[y]=x;
			}
		}
//		printf("i=%d cnt=%d res=%d size=%d\n",i,cnt,res,F.size());
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}