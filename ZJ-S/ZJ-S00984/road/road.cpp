#include<iostream>
#include<vector>
using namespace std;
struct City{
	int cost=1e9;
	vector<int> road[2];
}city[10005];
struct Town{
	int cost;
	int rcost1=1e9, rcost1_, rcost2=1e9, rcost2_;
	int rcost[10005];
	bool change;
}town[15];
int n, m, k, u, v, w;
long long ans, costcheck;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &w);
		city[min(u, v)].road[0].push_back(max(u, v));
		city[min(u, v)].road[1].push_back(w);
	}for(int i=0; i<k; i++){
		scanf("%d", &town[i].cost);
		costcheck+=town[i].cost;
		for(int j=0; j<n; j++){
			scanf("%d", &town[i].rcost[j]);
			if(town[i].rcost[j]<town[i].rcost1){
				town[i].rcost1=town[i].rcost[j];
				town[i].rcost1_=j;
			}
		}for(int j=0; j<n; j++){
			if(town[i].rcost[j]<town[i].rcost2 && j!=town[i].rcost1_){
				town[i].rcost2=town[i].rcost[j];
				town[i].rcost2_=j;
			}
		}
	}city[0].cost=0;
	if(costcheck==0 && k!=0){
		printf("0");
		return 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<city[i].road[0].size(); j++){
			v=city[i].road[0][j], w=city[i].road[1][j];
			city[v].cost=min(city[v].cost, w);
			city[i].cost=min(city[i].cost, w);
		}
	}for(int i=0; i<n; i++){
		ans+=city[i].cost;
	}printf("%lld", ans);
	/*for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			if(town[j].rcost1_!=i){
				if(town[j].cost+town[j].rcost1+town[j].rcost[i]<)
			}
		}
	}*/
}