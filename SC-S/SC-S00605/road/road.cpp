#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m,k,a[15][10005],u[N],v[N],w[N],c[N];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;
}