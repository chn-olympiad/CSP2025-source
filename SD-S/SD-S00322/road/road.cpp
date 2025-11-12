#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[10005],f[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	int cnt=0;
	sort(w+1,w+1+n);
	for(int i=n;i>1;i--){
		cnt+=w[i];
	}
	cout<<cnt;
	return 0;
} 
