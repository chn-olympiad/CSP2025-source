#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,u[1000006],v[1000005],w[1000005],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int ok=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)ok=0;
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	
	return 0;
}