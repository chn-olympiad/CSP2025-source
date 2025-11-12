#include<bits/stdc++.h>
using namespace std;
const int MAXN=0x3F3F3F3F;
unsigned long long n,m,k,ma[10020][10020],kmap[15][10020],u,v,w,ans;
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(i!=j) ma[i][j]=MAXN,ma[j][i]=MAXN;
		}
	}
	for(int i = 1;i<=m;i++){
		cin>>u>>v>>w;
		ma[u][v]=min(ma[u][v],w);
		ma[v][u]=ma[v][u];
	}
	for(int i = 1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ma[i][j]==MAXN) continue;
			for(int h=j+1;h<=n;h++){
				if(ma[i][h]==MAXN||ma[j][h]==MAXN) continue;
				if(ma[i][j]+ma[j][k]<=ma[i][j]) ma[i][j]=MAXN,ma[j][i]=MAXN;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]!=MAXN) ans+=a[i][j];
		}
	}
	for(int h=1;h<=k;h++){
		for(int i = 0;i<=n;i++){
			cin>>kmap[h][i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 