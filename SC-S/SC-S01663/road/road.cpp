#include<bits/stdc++.h>
using namespace std;
unsigned short n,k;
unsigned int m;

struct road{
	unsigned short u,v;
	unsigned int w;
};

struct cside{
	unsigned int cj;
	unsigned int a[10001];
};


road road_t;cside cside_t;
deque<road> roads;vector<cside> csides;
deque<road> o_roads;

void sort(){
	for(int i=0;i<roads.size();i++){
		for(int j=0;j<i;j++){
			if(roads[j].w > roads[j+1].w){
				swap(roads[j],roads[j+1]);
			}
		}
	}
}

unsigned long long best_of_this(){
	unsigned long long ans = 0;
	bool cities[10001] = {0};
	for(unsigned int i=0;i<roads.size();i++){
		if(cities[roads[i].u]&&cities[roads[i].w]){
			continue;
		}else{
			cities[roads[i].u] = 1;
			cities[roads[i].v] = 1;
			ans += roads[i].w;
		}
	}
	return ans;
}



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(unsigned int i=0;i<m;i++){
		cin >> road_t.u >> road_t.v >> road_t.w;
		roads.push_back(road_t);
	}
	for(short i=0;i<k;i++){
		cin >> cside_t.cj;
		for(int j=1;j<=n;j++){
			cin >> cside_t.a[j];
		}
		csides.push_back(cside_t);
	}
	
	sort();
	
	o_roads = roads;
	
    cout << best_of_this() << endl;
	
	
	
	return 0;
}