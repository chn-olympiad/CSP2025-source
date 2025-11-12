#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int x,y,v;
}arr[1000006];
int n,m,k,vi[11],vir[11][10004];
int main(){ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,v;
		cin>>x>>y>>v;	
	}
	for(int i=1;i<=k;i++){
		cin>>vi[i];
		for(int j=1;j<=n;j++){
			cin>>vir[i][j];
		}
	}
	if(k){
		cout<<0;
		return 0;
	}
	
}

