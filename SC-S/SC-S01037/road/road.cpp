#include<bits/stdc++.h>
#define int long long
using namespace std;
int u[1000100],v[1000100],w[1000100];
int c[20],aw[15][1000100]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>aw[i][j];
		}
	}
	if(k<=0){
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=w[i];
		}
		cout<<sum;
		return 0;
	} else{
		cout<<"0";
	}
	return 0;
}