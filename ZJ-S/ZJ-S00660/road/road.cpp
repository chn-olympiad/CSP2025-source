#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,sum,u[N],v[N],w[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	if(k==0) {
		cout<<sum;
		return 0;
	}
	return 0;
}