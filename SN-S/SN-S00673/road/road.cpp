#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010,MAXM=1000010,MAXK=11;
int n,m,k,u[MAXM],v[MAXM],w[MAXM],c[MAXK][MAXN],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			cin>>c[j][i];
		}
	}
	for(int i=1;i<=m;i++){
		ans+=w[i];
	}
	cout<<ans<<endl;
	return 0;
}
