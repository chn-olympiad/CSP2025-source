#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i+=2){
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
