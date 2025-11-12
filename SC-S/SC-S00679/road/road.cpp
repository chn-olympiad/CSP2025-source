#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[1000006],t[1000006],val[10000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>f[i]>>t[i]>>val[i];
	}
	sort(val+1,val+1+m);
	long long ans=0;
	for(int i=1;i<n;i++) ans+=val[i];
	cout<<ans<<endl;
	return 0;
}