#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>m>>m>>m;
		ans+=m;
	}
	cout<<ans;
	return 0;
}
