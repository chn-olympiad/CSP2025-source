#include<bits/stdc++.h>
using namespace std;


#define int long long

bool cmp(vector<int> x, vector<int> y){
    return x[2]<y[2];
}
struct DSU{
	vector<int> parent;
	vector<int> size;
	DSU(int n){
		parent.resize(n);
		size.resize(n, 1);
		for(int i = 0; i<n; i++){
			parent[i] = i;
		}
	}
	int find(int x){
		if(x != parent[x]){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}
	void unite(int x, int y){
		x = find(parent[x]), y = find(parent[y]);
		if(size[x]<size[y]){
			swap(x,y);
		}
		parent[y] = x;
		size[x] += size[y];
	}
	bool is_same(int x, int y){
		return parent[x] == parent[y];
	}	
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	DSU dsu(n);
	vector<vector<int> > dq;
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		vector<int> temp;
		temp.push_back(u-1);
		temp.push_back(v-1);
		temp.push_back(w);
		dq.push_back(temp);
	}
	sort(dq.begin(),dq.end(),cmp);
	
	int sum = 0;
	int used = 1;
	for(int i = 0; i<m; i++){
        if(dsu.is_same(dq[i][0],dq[i][1])){
        	continue;
		}
		used+=1;
        sum+=dq[i][2];
        dsu.unite(dq[i][0],dq[i][1]);
        if(used == n){
        	break;
		}
	}
	cout<<sum;
	return 0;
}
