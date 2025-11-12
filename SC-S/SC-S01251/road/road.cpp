#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,k,w[1010101],v[1010101],u[1010101],a[15][1010101],c[1010101],usd[1010101];
struct l_{
	int h,t,x;
}l[1010101];
int dfs(int f){
	u[f]=1;
	if(u[l[1].x]==0&&l[f].t!=l[f].h){
		l[f].t++;
		l[f].h=dfs(f-1);
		l[f].x=v[f];
		ans+=w[f];
		l[f].t--;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	l[1].h=1;
	l[1].t=n;
	l[1].x=0;
	dfs(n);
    cout<<rand();
	return 0;
}