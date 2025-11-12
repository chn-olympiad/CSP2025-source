#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,zx[maxn],k,c[maxn],a[maxn][maxn];
struct node{
	int u,v,w;
};
vector<node>eage;
bool cmp(node e,node r){
	return e.w<r.w;
}
long long ans=0;
int findzx(int now){
	if(zx[now]==now)return now;
	return zx[now]=findzx(zx[now]);
}
bool hebin(int q,int w){
	int zx1=findzx(q),zx2=findzx(w);
	if(zx1==zx2)return false;
	zx[zx1]=zx2;
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n+k;i++){
		zx[i]=i;
	}
	for(int i=1;i<=m;i++){
		int e,r,t;
		cin >> e >> r >> t;
		eage.push_back({e,r,t});
	}
	for(int j=1;j<=k;j++){
		cin >> c[j];
		for(int k=1;k<=n;k++){
			cin >> a[j][k];
			eage.push_back({n+j,k,a[j][k]});
		}
		
	}
	sort(eage.begin(),eage.end(),cmp);
	for(int i=0;i<eage.size();i++){
		if(hebin(eage[i].u,eage[i].v)){
			ans+=eage[i].w;
		}
	}
	cout << ans;
}