#include<bits/stdc++.h>
using namespace std;
int n,m,k,h;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		h+=z;
	}
	cout<<h;
	return 0;
}
