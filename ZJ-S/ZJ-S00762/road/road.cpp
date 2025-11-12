#include<bits/stdc++.h>
using namespace std;

struct side{
	int u,v,w;
};
side g[1000010];

bool cmp(side x,side y){
	return x.w<y.w;
}

int a[20][10010],c[10010],f[10010];

int find(int x){
	if(x==f[x]) return x;
	f[x]=find(f[x]);
	return f[x];
}

void merge(int x,int y){
	int u=find(x),v=find(y);
	f[x]=y;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		long long cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			if(cnt==n-1) break;
			if(find(g[i].u)!=find(g[i].v)){
				merge(f[g[i].u],f[g[i].v]);
				ans+=g[i].w;
				cnt++;
			}
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
