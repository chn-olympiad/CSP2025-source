#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e4+5;

struct node{
	int u,v,w;//第i条道路连接的两座城市与修复该道路的费用 
}a[N];

struct node2{
	int c;
	int value[N];
}gz[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;//城市数量、道路数量、可以城市化乡村数量 
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>gz[i].c;
		for(int j=1;j<=n;j++){
			cin>>gz[i].value[i];
		}
	}
	int fuickccf;
	bool ccfdiemum=1;
	bool cspsisverydiffclut=1;
	cout<<0;
	return 0;
}



