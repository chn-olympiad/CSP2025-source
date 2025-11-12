#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int pa[1000005];
int pb[1000005];
int fab[1000005];
int xf[10005];
int xj[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>pa[i]>>pb[i]>>fab[i];
	}
	for(int j=1;j<=n+1;j++){
		cin>>xf[j];
		cin>>xj[j];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans+=fab[i];
	}
	cout<<ans/(n/2);
	return 0;
} 
