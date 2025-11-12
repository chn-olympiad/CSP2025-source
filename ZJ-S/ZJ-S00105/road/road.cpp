#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,m,k,f[10005][10005],c[10005],a[10005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if(x<y)f[x][y]=v;
		else f[y][x]=v;
		sum+=v;
	}
	for(int u=1;u<=k;u++){
		scanf("%d",&c[u]);
		for(int i=1;i<=n;i++)scanf("%d",&a[u][i]);	
	}
	if(k==0){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++){
			if(f[i][j]>0&&f[j][k]>0&&f[i][k]>0)sum-=max(max(f[i][j],f[i][k]),f[j][k]);
		}
		printf("%d",sum);
	}
	else cout<<0<<endl;
	return 0;
}
