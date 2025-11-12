#include<bits/stdc++.h>
using namespace std;
int n,m,k,v1[10005],v2[10005],v3[10005],ans; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v1[i]>>v2[i]>>v3[i];
		ans+=v3[i];
	}
	cout<<ans;
	return 0;
}

