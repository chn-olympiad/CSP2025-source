#include<bits/stdc++.h>
#define inf 1e9
#define ll long long 
using namespace std;
ll n , m , k , d[100005] , vis[100005] , tong[100005] , ans = 999999999 , x , y , z , a[1000005] , kl;
struct Node{
	int v , w ;
};
queue<int> q;
vector<Node> e[100005] ;
void dijiesikela(ll s){
	for(int i = 0 ; i <= n ; i ++){
		d[i] = inf ;
	}
	d[s] = 0 ;
	vis[s] = 1 ;
	q.push(s) ;
	while(!q.empty()){
		int u = q.front() ;
		q.pop() ;
		vis[u] = 0 ;
		
		for(Node t:e[u]){

			if(t.w < 0){
				if(d[t.v] > t.w * (-1) + d[u]){
					d[t.v] =  t.w * (-1) + d[u];
					tong[t.v] = 1;
					if(vis[t.v] == 0){
						q.push(t.v) ;
						vis[t.v] = 1;
						cout << "->" ;
					}
				}
			}else{
				if(d[t.v] > t.w + d[u]){
					d[t.v] = t.w + d[u] ;
					if(vis[t.v] == 0){
						q.push(t.v) ;
						vis[t.v] = 1;
					}
				}
			}
		}
	}
}
int main(){
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	cin >> n >> m >> k ;
	for(int i = 1 ; i <= m ; i ++){
		cin >> x >> y >> z ;
		e[x].push_back({y , z}) ;
		e[y].push_back({x , z}) ;
	}
	for(int i = 1 ; i <= k ; i ++){
		cin >> a[i] ;
		for(int j = 1 ; j <= n ; j ++){
			cin >> y ;
			e[i].push_back({j , -1 * y}) ;
			e[j].push_back({i , -1 * y}) ;
		}
	} 
	for(int i = 1 ; i <= n ; i ++){
		memset(vis , 0 , sizeof(vis)) ;
		memset(tong , 0 , sizeof(tong)) ;
		memset(d , 0 , sizeof(d)) ;
		dijiesikela(i) ;
		ll sum = -99999999 ;
		kl = 0 ; 
		for(int j = 1 ; j <= n ; j ++){
			if(tong[j] != 0){
				kl += a[j] ;
			}
		}
		for(int j = 1 ; j <= n ; j ++){
			sum = max(sum , d[j] + kl) ;
		}
		if(ans > sum){
			ans = sum ;
			cout << i << endl ;
		}
	}
	cout << ans ;
	return 0;
}
