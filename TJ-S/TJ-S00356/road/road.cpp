#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	while(k--){
		for(int i=1;i<=n+1;i++){
			int q;
			cin>>q;
		}
	}
	cout<<ans;
	return 0;
}

