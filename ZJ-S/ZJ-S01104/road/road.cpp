#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
