#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
bool b[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e9;
		}
	}
	while(m--){
		scanf("%d%d%d",&u,&v,&w);
		if(u>v) swap(u,v);
		a[u][v]=min(a[u][v],w);
	}
	memset(b+1,true,n);
	for(int q=1;q<n;q++){
		int p=1e9,x,y;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i][j]<p&&(b[i]||b[j])){
					p=a[i][j];
					x=i;
					y=j;
				}
			}
		}
		ans+=p;
		b[x]=false;
		b[y]=false;
	}
	printf("%lld",ans);
	return 0;
}
