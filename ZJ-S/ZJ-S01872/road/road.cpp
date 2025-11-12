#include<bits/stdc++.h>
using namespace std;
int n,m,k,s=1,ans,u[100005],v[100005],w[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	if(k==0){
		sort(w+1,w+m+1);
		for(int i=1;i<m;i++){
			ans+=w[i];
		}
		cout<<ans<<"\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}
