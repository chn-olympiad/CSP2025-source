#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[1010][100010],c[20],u,v,w,l,g,x[100000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=100000;j++){
			if(i==j) a[i][j]=0;
			else a[i][j]=INT_MAX;
		}
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		fro(int j=1;j<=n+1;j++){
			cin>>w;
			a[n+i][j]=min(a[n+i][j],w);
			a[j][n+i]=min(a[j][n+i],w);
		}
	}
	for(int h=1;h<=n+k;h++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=a[j][i]=min(a[i][j],a[i][h]+c[h-n]+a[h][j]);
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		if(i==n/2){
			for(int j=1;j<=n/2;j++) c[++g]=a[i][j];
		}else{
			for(int j=1;j<=n;j++) c[++g]=[i][j];
		}
	}
	sort(a+1,a+g+1);
	for(int i=1;i<=n;i++) l+=c[i];
	cout<<l;
    return 0;
}
