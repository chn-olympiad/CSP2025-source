#include<bits/stdc++.h>
#define int long long
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define forrr(i,a,b) for(int i=a;i>=n;i--)
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
struct ro{
	int u,v,w;
}e[1000010],anss[10010];
int top=0;
int xz[20][100010];
bool cmp(ro a,ro b){
	return a.w<b.w;
}
int fa[10010];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,kk;
//	cin>>n>>m>>k;
	scanf("%lld%lld%lld",&n,&m,&kk);
	
	forr(i,1,m){
//		cin>>e[i].u>>e[i].v>>e[i].w;//城市之间的边 
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
//	
	forr(i,1,kk){
		for(int j=0;j<=n;j++){
			scanf("%lld",&xz[i][j]);
		}
	}
	int ans1=1e18,ans2=0;
	for(int i=0;i<(1<<kk);i++){//乡镇方案 
		forr(i,1,m) anss[i]=e[i];
//		cout<<"@@\n";
		ans2=0;
		int k=0;
		int top2=m;
		while((i>>k)>0){
//			cout<<11<<'\n';
			if((i>>k)&1==0) continue;
			ans2+=xz[k+1][0];
			forr(j,1,n){//连接城镇 
				anss[++top2]={kk+1+n,j,xz[k+1][j]};
//				cout<<k+1<<' '<<j<<' '<<xz[k+1][j]<<'\n';
			}
			k++;
		}
		sort(anss+1,anss+1+top2,cmp);
		forr(j,1,top2) fa[j]=j;
		forr(j,1,top2){//求最小生成树 
			int x=find(anss[j].u),y=find(anss[j].v);
//			cout<<anss[j].u<<' '<<anss[j].v<<'\n';
			if(x!=y){
				ans2+=anss[j].w;
				fa[x]=y;
			}
		}
		ans1=min(ans2,ans1);
	}
	printf("%lld",ans1);
	/*
	4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

	*/
 	return 0;
 }
