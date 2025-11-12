#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,t1,t2,t3;
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>t1>>t2>>t3;
		ans+=t3;
	} 
	cout<<ans;
	return 0;
}