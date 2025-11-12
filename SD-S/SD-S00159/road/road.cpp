#include<bits/stdc++.h>
using namespace std;

int z[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>z[i];
	}
	sort(z+1,z+n+1);
	int cnt=0;
	for(int i=1;i<=n-1;i++){
		cnt+=z[i];
	}
	cout<<cnt;
}
