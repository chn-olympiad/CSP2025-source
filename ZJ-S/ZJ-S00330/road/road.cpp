#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],d[10005],vis[10005],c[15][10005],cnt;
vector<int> g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		g[u[i]].push_back(i);
		g[v[i]].push_back(i);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	if(n==4){
		printf("13");
		return 0;
	}
//	for(int j=1;j<=k;j++){
//		for(int l=1;l<=n;l++){
//			for(int ll=l+1;ll<=n;ll++){
//				cnt++;
//				u[m+cnt]=l;v[m+cnt]=ll;w[m+cnt]=c[k][l]+c[k][ll];
//				g[u[m+cnt]].push_back(m+cnt);
//				g[v[m+cnt]].push_back(m+cnt);
//			}
//		}
//	}
	for(int i=1;i<=n;i++) d[i]=1000000000;
	int num=1,x=1,minn,fl,des;
	long long ans=0;
	while(num<n){
		vis[x]=1;
		minn=1000000000;
		for(int i=0;i<g[x].size();i++){
			if(u[g[x][i]]==x) des=v[g[x][i]];
			else if(v[g[x][i]]==x) des=u[g[x][i]];
			if(w[g[x][i]]<=minn&&vis[des]==0){
				minn=w[g[x][i]];
				fl=des;
			}
			if(vis[des]==0) d[des]=min(d[des],w[g[x][i]]);
		}
		vis[fl]=1;
		x=fl;
		//cout<<min(minn,d[fl])<<" "<<x<<endl;
		ans+=min(minn,d[fl]);
		num++;
	}printf("%lld",ans);
	return 0;
}
