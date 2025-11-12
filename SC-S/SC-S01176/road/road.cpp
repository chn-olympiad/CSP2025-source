#include<bits/stdc++.h>
using namespace std;
int n0,m0,k,vi[11][10001],f[1006];
int x,v,u,w,r[1006][1006],mi,mip,cot;
bool bk[1006];
long long ans=LONG_LONG_MAX;
bool check(int n){
	for(int i=1;i<=n;i++){
		if(bk[i]==0) return 0;
	}
	return 1;
}
long long solve(int n){
	long long as=0;
	memset(bk,0,sizeof(bk));
	memset(f,0,sizeof(f));
	f[1]=1;
	bk[1]=1;
	cot=1;
	while(cot<n){
		mi=INT_MAX;
		for(int i=1;i<=cot;i++){
			if(bk[f[i]]){
				for(int j=1;j<=n;j++){
					if(j==f[i] or bk[j]){
						continue;
					}
					if(r[f[i]][j]<mi and r[f[i]][j]>=0){
						mip=j;
						mi=r[f[i]][j];
					}
				}
			}
		}
		cot++;
		f[cot]=mip;
		bk[mip]=1;
		as+=mi;
	}
	return as;
}
void dfs(int x,int n){
	if(x==k){
		ans=min(ans,solve(n));
		return;
	}
	dfs(x+1,n);
	n++;
	for(int i=1;i<=n0;i++){
		r[i][n]=vi[x][i];
		r[n][i]=r[i][n];
	}
	dfs(x+1,n);
	n--;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n0>>m0>>k;
	for(int i=1;i<=n0+k;i++){
		for(int j=1;j<=n0+k;j++){
			r[i][j]=-1;
			r[j][i]=-1;
		}
	}
	for(int i=1;i<=m0;i++){
		cin>>v>>u>>w;
		r[v][u]=w;
		r[u][v]=w;
	}
	for(int i=0;i<k;i++){
		cin>>vi[i][0];
		for(int j=1;j<=n0;j++){
			cin>>vi[i][j];
		}
	}
	if(k==0){
		cout<<solve(n0);
		return 0;
	}
	dfs(0,n0);
	cout<<ans;
	return 0;
}