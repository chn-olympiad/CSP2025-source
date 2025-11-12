#include<bits/stdc++.h>
using namespace std;
int a[10010][10010],b[15][10010],e[15];
bool c[10010][10010],d[15][10010],f[15];
int m,n,k,lin1,lin2,lin3,minx=(1<<20)-1;
long long ans=0;
int dfs(int from,int to,int minn,int all){
	if(all>minn) return(1<<20)-1;
	int t=(1<<20)-1;
	for(int l=1;l<=k;l++){
		if(b[l][from]*(!d[l][from])+b[l][to]*(!d[l][to])+e[l]*(!f[l])<minn){
			minn=b[l][from]*(!d[l][from])+b[l][to]*(!d[l][to])+e[l]*(!f[l]);
			lin1=l;
		}
	}
	for(int i=1;i<=n&&i!=from&&i!=to;i++){
		if(t>dfs(i,to,minn,all+a[from][i]*(!c[from][i]))){
			lin2=i;
			t=dfs(i,to,minn,all+a[from][i]*(!c[from][i]));
		}
		
	}
	if(t<minn){
		c[from][lin2]=true;
		all+=a[from][lin2];
	}
	else{
		all+=b[lin1][from]*(!d[lin1][from])+b[lin1][to]*(!d[lin1][to])+e[lin1]*(!f[lin1]);
		b[lin1][from]=true;
		b[lin1][to]=true;
		f[lin1]=true;
		
	}
	return all;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>lin1>>lin2>>lin3;
		a[lin1][lin2]=lin3;
	}
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=dfs(i,j,minx,0);
		}
	}
	cout<<ans/3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
