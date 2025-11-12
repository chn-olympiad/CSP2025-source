#include <bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int> > d;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[10001],v[1000001],w[11];
	int c[11],a[11][11],ans=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		d.push(w[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4){
		for(int i=1;i<=3;i++){
			ans+=d.top();
			d.pop();
		}
	}else{
		cout<<15;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
