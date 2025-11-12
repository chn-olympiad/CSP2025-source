#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000100],v[1000100],w[1000100],vil[15][1010],vilsum[15],maxw,maxc,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		maxw+=w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>vil[i][j];
			if(j==0)maxc=max(maxc,vil[0][j]);
			vilsum[i]+=vil[i][j];
		}
	}
	if(maxc==0){
		cout<<0;
		return 0;
	}
	ans=maxw;
	for(int i=1;i<=k;i++){
		ans=min(ans,vilsum[i]);
	}
	cout<<ans;
	return 0;
}