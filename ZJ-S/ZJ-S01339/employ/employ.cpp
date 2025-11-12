#include<bits/stdc++.h>
#define fo(i , x , y) for(int i = x ; i <= y ; i++)
#define go(i , x , y) for(int i = x ; i >= y ; i--)
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n , m , c[maxn];
string s;
int ans , t[maxn];
bool used[maxn];
void dfs(int now , int k){
	if(now > n){
		if(n - k >= m) ans++;
		return;
	}
	if(k > n - m) return;
	fo(i , 1 , n){
		if(used[i]) continue;
		used[i] = true;
		if(s[now] == '0') dfs(now + 1 , k + 1);
		else if(k >= c[i]) dfs(now + 1 , k + 1);
		else dfs(now + 1 , k);
		used[i] = false;
	}
}
void solve1(){
	dfs(1 , 0);
	cout << ans << '\n';
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m >> s;
	fo(i , 1 , n)
		cin >> c[i];
	s = " " + s;
	solve1();
}
