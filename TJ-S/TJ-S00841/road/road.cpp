#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int jl[15];

struct node{
	int bz,zz;
}; 
vector<node> jll;
vector<node> dl;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dl[a].bz=c;
		dl[a].zz=c;
		dl[b].bz=a;
		dl[b].zz=c;
	}
	for (int i=1;i<=k;i++){
		cin>>jl[i];
		for (int j=1;j<=n;j++){
			int y;
			cin>>y;
			jll[i].bz=j;
			jll[i].zz=y;
		}
	}
	
	return 0;
}
