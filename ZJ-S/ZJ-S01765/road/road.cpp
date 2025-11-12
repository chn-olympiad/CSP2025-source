#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+10,M=1e6+10;
int c[11],a[11][N];
struct R{
	int u,v,w;
	bool operator < (R b){
		return w<b.w;
	}
}road[M];
int fa[N],cnt=0;
inline int ser(int k){
	if(fa[k]==k)return k;
	return fa[k]=ser(fa[k]);
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
	}
	sort(road+1,road+1+m);
	ll ans=0;
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(ser(road[i].u)!=ser(road[i].v)){
			fa[fa[road[i].u]]=fa[road[i].v];
			ans+=road[i].w;
		}
	}
	cout<<ans;
	return 0;
}