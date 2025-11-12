#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,k;
int u,v,w,a;
int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	int c;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a;
		}
	}
	cout<<sum;
	return 0;
}