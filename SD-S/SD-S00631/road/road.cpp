#include <bits/stdc++.h>
using namespace std;

vector<int> edges[10001];
int n , m , k , c[10001] , d[10011][10011] , ans , sum;
bool b[10011];


void dfs(int x){
	b[x] = 1;
	for(auto y : edges[x]){
		if(c[y] && !b[y]){
			dfs(y);
			ans += d[x][y];
			ans += c[y];
			for(auto q : edges[x]){
				if(c[q]){
					
				}else{
					if(!b[q]){
						b[q] = 1;
						sum += d[x][q];
						dfs(q);
					}
				}
			}
			ans = min(ans , sum);
			sum = ans;
		}
		else{
			if(!b[y]){
				dfs(y);
				ans += d[x][y];
				sum = ans;
			}
		}
	}
}

int main(){
	freopen("rode.in" , "r" , stdin);
	freopen("rode.out" , "w" , stdout);
	scanf("%d%d%d",&n , &m , &k);
	for(int i = 1 ; i <= m ; i++){
		int u , v , w;
		scanf("%d%d%d",&u , &v , &w);
		edges[u].push_back(v);
		edges[v].push_back(u);
		d[u][v] = w;
		d[v][u] = w;
	}
	for(int i = m + 1 ; i <= m + k ; i++){
		int a[100001];
		scanf("%d", &c[i]);
		for(int j = 1 ; j <= n ; j++){
			scanf("%d",&a[j]);
			edges[i].push_back(j);
			edges[j].push_back(i);
			d[i][j] = a[j];
			d[j][i] = a[j];
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
