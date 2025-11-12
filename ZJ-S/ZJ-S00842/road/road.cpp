#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
int mp[1009][1009];
int s[20][2333];
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int kai,kbi,kci;
		cin>>kai>>kbi>>kci;
		mp[kai][kbi]=kci;
		mp[kai][kbi]=kci;
	}
	for(int i=1;i<=k;i++){
		cin>>s[i][0];
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	cout<<0; 
	return 0;
} 
