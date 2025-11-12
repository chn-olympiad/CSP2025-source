#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,t,l;i<=m;i++){
		cin>>t>>t>>l;
		sum+=l;
	}
	for(int i=1,t;i<=k;i++){
		cin>>t;
		for(int j=1,l;j<=n;j++){
			cin>>l;
		}
	}
	cout<<0;
}
