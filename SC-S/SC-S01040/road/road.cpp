#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10; 
int n,m,k;

struct Edge{
	int u,v,w;
}a[N];

int c[11];
int v[20][N];

bool cmp(const Edge &x,const Edge &y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in ","r",stdin);	
	freopen("road.out ","w",stdout);	
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i=1;i<=k;i++){//表示在第i个城市修建的费用和要连边的代价  
		cin >> c[i];
		for(int j=1;j<=n;j++) cin >> v[i][j]; 
	}
	//当k==0时 代表没有可以改装的城市 直接库鲁斯卡尔
	int ans=0;
	if(k==0){
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fx=find(u),fy=find(v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=w;
			}
		}
	}else{
		//c==0 表示直接可以连接 
		int cnt=0;
		//考虑加边 
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				int w=v[i][j];
				cnt++;
				a[m+cnt].u=i,a[m+cnt].v=j,a[m+cnt].w=w;
			}
		}
		sort(a+1,a+1+m+cnt,cmp);
		for(int i=1;i<=m+cnt;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fx=find(u),fy=find(v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=w;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
