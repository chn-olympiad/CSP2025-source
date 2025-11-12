#include<bits/stdc++.h>
using namespace std;
int n,m,k,ant;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>x[i][1]>>x[i][2]>>x[i][3]>>x[i][4]>>x[i][5];
	}
	for(int i=1;i<n;i++){
		ant+=a[i][3];
	}
	cout<<ant;
	return 0;
}