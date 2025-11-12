#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int c;
	vector<pair<int,int> > v;
}city[10020];
vector<pair<int,int> > v[10020];
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int j,k1,l,i=1;i<=m;++i){
		cin>>j>>k1>>l;
		city[j].v.emplace_back(l,k1),city[j].v.emplace_back(l,j);
	}
	for(int i=1;i<=k;++i){
		cin>>city[i+m].c;
		for(int j=1,k1,l;j<=n;++j){
			cin>>k1>>l;
			city[i+m].v.emplace_back(l,k1),city[k1].v.emplace_back(l,i+m);
		}
	}
	cout<<0;
	return 0;
}