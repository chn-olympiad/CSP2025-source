#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool fl[10005];
long long r[10005][10005],a[15][10005],c[15];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(r,9999999,sizeof(r));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		r[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		r[u][v]=min(w,r[u][v]);
		r[v][u]=min(w,r[v][u]);
	}
	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		///*
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l)continue;
				if(c[i]+a[i][j]+a[i][l] <= r[j][l]){
					ans+=c[i];
					c[i]=0;
					r[j][l]=c[i]+a[i][j]+a[i][l];
					r[l][j]=c[i]+a[i][j]+a[i][l];
				}
			}
		}
		//*/
	}
	
	for(int p=1;p<=n;p++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				r[x][y]=min(r[x][y],r[p][y]+r[x][p]);
			}
		}
	}
	for(int i=1;i<n;i++){
		r[i][i]=999999999;
	}
	for(int i=1;i<=n;i++){
		long long add=999999999;
		for(int j=i;j<=n;j++){
			add=min(r[j][i],add);
			//cout<<r[i][j]<<" ";
		}
		//cout<<"\n";
		//cout<<add<<"\n";
		ans+=add;
	}
	printf("%lld",ans);
	return 0;
}
