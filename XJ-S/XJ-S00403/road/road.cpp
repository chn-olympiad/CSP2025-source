#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
int n,m,k;
long long num;
vector<node>e[2000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		num+=w;
		e[u].push_back({v,w});
		e[v].push_back({v,w});
	}
	cout<<num;
	return 0;
}
