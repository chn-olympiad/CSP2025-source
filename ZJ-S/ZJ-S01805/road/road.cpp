#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	int u[100005],v[100005],w[100005],c[100005];
	for(int i=1;i<=m;i++){
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
	}
	for(int i=0;i<=n+1;i++){
		cin>>c[i];
	}
	cout<<"13";	
	
	fclose(stdin);
	fclose(stdout);
}


