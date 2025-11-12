#include<iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[1000],v[1000],w[1000];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int a;
			cin>>a;
			cnt+=a;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}