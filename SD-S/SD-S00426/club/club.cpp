#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn] , b[maxn] , c[maxn];
vector < int > v1 , v2 , v3;
struct Node{
	int gt2 , gt3 , id;
	friend bool operator < (Node x , Node y){
		return min(x.gt2 , x.gt3) < min(y.gt2 , y.gt3);
	}
};
void solve(){
	v1.clear() , v2.clear() , v3.clear();
	int n ; cin >> n ;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		if(a[i] > b[i] && a[i] > c[i]) v1.push_back(i);
		else if(b[i] > a[i] && b[i] > c[i]) v2.push_back(i);
		else v3.push_back(i);
	} if(v1.size() <= n / 2 && v2.size() <= n / 2 && v3.size() <= n / 2){
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++) ans += max(a[i] , max(b[i] , c[i]));
		cout << ans << endl; return;
	}
	if(v2.size() > n / 2) swap(v1 , v2) , swap(a , b);
	if(v3.size() > n / 2) swap(v1 , v3) , swap(a , c);
	vector < Node > value; 
	for(int i = 0 ; i < v1.size() ; i ++) 
		value.push_back({a[v1[i]] - b[v1[i]] , a[v1[i]] - c[v1[i]] , v1[i]});
	sort(value.begin() , value.end());
	int ans = 0;
	for(int i = 0 ; i < (value.size() - n / 2) ; i ++)
		if(value[i].gt2 < value[i].gt3) ans += b[value[i].id] ; 
		else ans += c[value[i].id];
	for(int i = value.size() - n / 2 ; i < value.size() ; i ++) ans += a[value[i].id];
	for(int i = 0 ; i < v2.size() ; i ++) ans += b[v2[i]];
	for(int i = 0 ; i < v3.size() ; i ++) ans += c[v3[i]];
	cout << ans << endl;
}
int main(){
	ios :: sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T ; cin >> T;
	while(T --) solve(); 
	return 0;
} 
