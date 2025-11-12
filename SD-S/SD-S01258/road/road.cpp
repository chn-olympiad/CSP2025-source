#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+7;
const int M=1e4+7;

int fa[M],c[17],dis[M][17];
int n,m,k,ans;

struct node{
	int l,r,val;
}a[N];

bool cmp(node x,node y){
	return x.val<y.val;
}

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void kruskal(){
	iota(fa+1,fa+n+1,1);
	for(int i=1;i<=m;i++){
		int x=find(a[i].l),y=find(a[i].r);
		if(x==y) continue;
		fa[x]=y;
		int ans1=1e18;
		for(int j=1;j<=k;j++){
			ans1=min(ans1,c[j]+dis[x][j]+dis[y][j]);
		}
		if(ans1<=a[i].val){
			for(int j=1;j<=k;j++){
				if(c[j]+dis[x][j]+dis[y][j]==ans1){
					c[j]=dis[y][j]=0;
				}
			}
		} else {
			for(int j=1;j<=k;j++){
				dis[y][j]=min(dis[x][j],dis[y][j]);
			}
		}
		ans+=min(ans1,a[i].val);
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].val;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>dis[j][i];
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}
