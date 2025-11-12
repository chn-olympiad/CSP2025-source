#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[15][100005],vv[15],f[100005],kk[15];
struct edge{
	int u,v,w;
}e[1000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void hebin(int x,int y){
	f[x]=find(f[y]);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
	}
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>vv[i];
		for(int j=1;j<=n;j++)
		cin>>v[i][j];
	}
	sort(e+1,e+m+1,cmp);
	int vis=1,cnt=0,ans=0;
	while(cnt<m){
		cnt+=1;
		if(find(e[cnt].u)!=find(e[cnt].v)){
			hebin(f[e[cnt].u],f[e[cnt].v]);
			ans+=e[cnt].w;
		}
	}
	cout<<ans;
	return 0;
//	for(int b=0;b<=1<<k;b++){
//		int ans=0,mm=m;
//		for(int i=1,o=b;i<=k;i++){
//			kk[i]=o%2;
//			o/=2;
//			if(kk[i]==1)
//			ans+=vv[i];
//		}
//		for(int i=1;i<=k;i++){
//			if(kk[i]==1){
//				for(int ii=1;ii<=n;ii++)
//			}
//		}
//	}
}
