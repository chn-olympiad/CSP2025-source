#include<bits/stdc++.h>
using namespace std;
int n,m,ans,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==m+1){
		for(int i=1;i<=m;i++){
			int t;
			cin>>t>>t>>t;
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}