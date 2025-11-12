#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<node > MAP1(m);
	for(int i=0;i<m;i++){
		cin>>MAP1[i].u>>MAP1[i].v>>MAP1[i].w;
	}
	vector<node > MAP2(n);
	for(int i=0;i<m;i++){
		cin>>MAP2[i].u>>MAP2[i].v>>MAP2[i].w;
	}cout<<m*n%1234567;
	
	return 0;
}
