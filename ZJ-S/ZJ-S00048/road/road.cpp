#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long u[N],v[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+n+1);
	long long sum=0;
	for(int i=1;i<n;i++){
		sum+=w[i];
	}
	cout<<sum;
	return 0;
}
