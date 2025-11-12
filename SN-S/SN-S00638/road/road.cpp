#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,u[100010],v[100010],w[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
		sort(w+1,w+1+m);
		for(int i=1;i<=n-1;i++) ans+=w[i];
		cout<<ans;
	}
	return 0;
}
