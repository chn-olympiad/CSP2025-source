#include <iostream>
#include <vector>
using namespace std;
const int maxn = 505;
int s[maxn] , c[maxn] , tong[maxn];
int n , m , ans = 0; 
void dfs(int x , vector < int > v){
	if(x > n){ int cnt = 0 , tot = 0;
		if(v.empty()) return;
		for(int i = 0 ; i < v.size() ; i ++){
			if(cnt >= c[v[i]]) {
				++ cnt ; continue;
			}
			if(s[i + 1] == 0) ++ cnt;
			else ++ tot;
		} if(tot >= m) ++ ans;
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(tong[i] == 0) tong[i] = 1;
		else continue;
		v.push_back(i);
		dfs(x + 1 , v);
		v.pop_back(); tong[i] = 0;
	}
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) {
		char ch ; cin >> ch; 
		s[i] = ch - '0';
	}
	for(int i = 1 ; i <= n ; i ++) cin >> c[i];
	vector < int > tmp;
	dfs(1 , tmp); cout << ans << endl;
	return 0;
} 
