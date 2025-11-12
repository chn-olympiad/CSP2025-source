#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	int anser=N;
	for(int i=1;i<=k;i++){
		
		int num;
		cin>>num;
		anser+=num;
		for(int j=0;j<=n;j++){
			int sum;
			cin>>sum;
			num+=sum;
		}
		if(num<anser)anser=num;
	}
	cout<<anser;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
