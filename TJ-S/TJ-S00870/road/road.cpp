#include<bits/stdc++.h>
using namespace std;

struct st{
	int v , w;
};

int n , m , k;
long long ans;
vector<st>e[10005];
int d[10005];

int vis[10015];

void disckla(int s){
	for(int i = 0;i <= n+k;i++){
		d[i] = 1e9;
	}
	d[s] = 0;
	
	for(int i = 1;i <= n;i++){
		int u = 0;
		for(int j = 1;j <= n;j++){
			if(!vis[j]){
				if(d[u] > d[j] && d[j] != 1e9){
					u = j;
				}
			}
		}
		
		vis[u] = 1;
		
		for(st v:e[u]){
			if(v.v )
			if(d[u] + v.w < d[v.v]){
				d[v.v] = d[u] + v.w;
			}
		}
	}
}

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1;i <= m;i++){
		int x , y , z;
		cin >> x >> y >> z;
		e[x].push_back({y , z});
		e[y].push_back({x , z});
	}
	
	if(k == 0){
		disckla(1);
		
		long long ans = 0;
		for(int i = 2;i <= n;i++){
			ans += d[i];
		}
		cout<<ans;
	}else{
		cout<<0;
	}
		
	return 0;
}	
