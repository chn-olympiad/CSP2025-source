#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 35 , M = 1e6 + 5;
struct node{
	int id , val;
};
vector<node>v[N];
int n , m , k;
int ans = 1e18;
bool vis[N];
void dfs(int now , int cnt , int num){
	if(num == n - 1){
		ans = min(ans , cnt);
		return ;
	}
	vis[now] = true;
	int len = v[now].size();
	for(int i=0;i<len;i++){
		int nxt = v[now][i].id;
		int jia = v[now][i].val;
		if(!vis[nxt]){
			dfs(nxt , cnt + jia , num + 1);
		}	
	}
	vis[now] = false;
	return ;
}
int c[15];
int jilu[15];
int a[15][N];
void dg(int now , int cnt){
	if(now == k + 1){
		dfs(1 , cnt , 0);
		return ;
	}
	dg(now + 1 , cnt);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i != j){
				v[i].push_back({j , a[now][i] + a[now][j]});
			}
		}
	}
	dg(now + 1 , cnt + c[now]);
	return ;
}
signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);	
	cin >> n >> m >> k; 
	for(int i=1;i<=m;i++){
		int u , e , w;
		cin >> u >> e >> w;
		v[u].push_back((node){e , w});
		v[e].push_back((node){u , w});
	}
	if(k <= 0){
		dfs(1 , 0 , 0);
		cout << ans << endl;
	}
	else{
		bool flag = true;
		for(int i=1;i<=k;i++){
			cin >> c[i];
			if(c[i] != 0){
				flag = false;
			}
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
			}
		}
		if(flag){			
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(a[i][j] == 0){
						jilu[i] = j;
					}
				}
			}
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(jilu[i] != j) v[jilu[i]].push_back({j , a[i][j]});
				}
			}
			dfs(1 , 0 , 0);
			cout << ans << endl;
		}else{
			dg(1 , 0);
			cout << ans << endl;
		}
	}
}
