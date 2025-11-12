#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long w;
		cin>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
