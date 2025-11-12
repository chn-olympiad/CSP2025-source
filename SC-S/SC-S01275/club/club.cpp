#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
ll t;
ll n, maxn = -1;
struct node{
	ll a, b, c, d;
};
node club[100005];
void dfs(ll ax, ll bx, ll cx, ll x, ll sum){
	if(ax > (n / 2) || bx > (n / 2) || cx > (n / 2)) return;
	if(x == n + 1){
		maxn = max(maxn, sum);
		return;
	}
	dfs(ax + 1, bx, cx, x + 1, sum + club[x].a);
	dfs(ax, bx + 1, cx, x + 1, sum + club[x].b);
	dfs(ax, bx, cx + 1, x + 1, sum + club[x].c);
}
bool cmp(node u, node v){
	return u.a > v.a;
}
bool cmp1(node u, node v){
	return u.d > v.d;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while(t --){
		maxn = -1;
		cin >> n;
		ll az, bz, cz;
		for(int i = 1; i <= n; i ++){
			cin >> club[i].a >> club[i].b >> club[i].c;
			if(club[i].a) az ++;
			if(club[i].b) bz ++;
			if(club[i].c) cz ++;
		}
		if(bz == cz && bz == n){
			sort(club + 1, club + n + 1, cmp);
			ll o = 0;
			for(int i = 1; i <= n / 2; i ++){
				o += club[i].a;
			}
			cout << o << endl;
			continue;
		} else if(cz == n){
			for(int i = 1; i <= n / 2; i ++){
				club[i].d = club[i].a - club[i].b;
				sort(club + 1, club + n + 1, cmp1);
				ll o = 0;
				for(int i = 1; i <= n / 2; i ++){
					o += club[i].a;
				}
				for(int i = 1; i <= n / 2; i ++){
					o += club[i].b;
				}
				cout << o;
			}
		}
		dfs(0, 0, 0, 1, 0);
		cout << maxn << endl;
	}
	return 0;
}