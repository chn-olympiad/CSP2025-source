#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int n,m,k,u,v,w,sum=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
