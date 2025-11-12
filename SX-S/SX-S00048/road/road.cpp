#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[1000000],e[1000000],f[1000000],g[1000000],h[1000000],i[1000000],j[1000000],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int ii=1;ii<= b;ii++){
		cin>>d[ii]>>e[ii]>>f[ii];
		cnt+=d[ii]/2;
	}
	for(int ii=1;ii<=c;ii++){
		cin>>g[ii]>>h[ii]>>i[ii]>>j[ii];
		if(g[ii]<g[ii-1]){

			cnt+=g[ii]/2;
			cnt+=j[ii]/4;
		}
	}

	cout<<cnt;
	return 0;
}