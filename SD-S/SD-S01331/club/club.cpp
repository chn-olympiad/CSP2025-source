#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lowbit(x) x & (-x)
#define pii pair<int, int>
#define INF 0x3f3f3f3f
const int MAXN = 3e5 + 3, sec = 900;
int n;
//struct node{
//	int val1, val2, val3;
//	int id;
//}a[MAXN]; 
struct Node{
	int p, id;
	short w;
	//wÎª1Î»ÖÃÎª1... 
}qwq[MAXN];
bool cmp1(Node x, Node y){
	if(x.p == y.p) return x.id < y.id;
	return x.p > y.p;
}
short vis[MAXN];
ll x[5];
/*
4
50 2 0
2 50 0
50 2 0
50 2 0
*/
/*
2
10 9 8
4 0 0
*/
void solve(){
	cin >> n;
	int nn = 3 * n;
	for(int i = 1;i <= n;i++){
		vis[i] = -1;
	}
	memset(x, 0, sizeof x);
	for(int i = 1;i <= nn;i++){
		qwq[i].id = (i + 2) / 3;
		qwq[i].w = i % 3 == 0 ? 3 : i % 3;
		cin >> qwq[i].p;
	} 
	sort(qwq + 1, qwq + nn + 1, cmp1);
	int res = 0;
	for(int i = 1;i <= nn;i++){
		if(vis[qwq[i].id] == -1){
			if(x[qwq[i].w] < n / 2){
				res += qwq[i].p; 
				vis[qwq[i].id] = qwq[i].w;
				x[qwq[i].w]++;
			}
		}
	}
	cout << res << '\n';
}
int main(){
	IOS
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _;
	cin >> _;
	while(_--){
		solve();
	}
//	while(ti - clock() < sec)
//	cout << "\n\n\n" << 1000 * clock() / CLOCKS_PER_SEC << " ms";
	return 0;
}
