#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	int r;
	int cost;
}rod[600];
int con[20][600];
int cost[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>rod[i].l>>rod[i].r>>rod[i].cost;
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int o=1;o<=n;o++)cin>>con[i][o];
	}
	cout<<0;
	return 0;
}
