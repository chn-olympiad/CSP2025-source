#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long sum;
struct W{
	int li,ri,wi;
}w[1000010];
int c[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>w[i].li>>w[i].ri>>w[i].wi ;
		sum+=w[i].wi ;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
	}
	cout<<sum;
	
	return 0;
} 
