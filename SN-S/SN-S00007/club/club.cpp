#include<bits/stdc++.h>
using namespace std;
long long sum[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			sum[i]=sum[i]+max({x,y,z});
		}
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<'\n';
	}
	return 0;
}
