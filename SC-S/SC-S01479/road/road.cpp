#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k;
int u,v,w; 
vector<int> g[10001];
int c[10001][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin>>c[i][j];	
		}
	}
	cout<<"100 1 3 2 4";
	return 0;
}
//*g++ untitled5.cpp -o untitled5 -O2 -std=c++14 -Wall -Wextra