#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int int
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N = 100 + 10;
int n, m; struct node {int val, id; } a[N]; 

bool cmp(node a, node b) {
	return a.val > b.val; 
}

void solve() {
	
	cin >> n >> m; 
	for(int i=1;i<=n*m;i++) {
		cin >> a[i].val; a[i].id = i; 
	}
	
	sort(a+1, a+n*m+1, cmp); 
	for(int i=1;i<=n*m;i++) {
		if(a[i].id == 1) {
			cout << (i+n-1)/n << ' '; 
			// each 2n one range
			//7   (7+n-1)/n    7%8=7   7>4 4+1-(7-4)
			int k = i%(2*n); if(k == 0) k = 2*n; 
			if(k <= n) cout << k; 
			else cout << n+1-(k-n); 
			return ; 
		}
	}
	
}

signed main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout); 

//  int _; cin >> _; while(_--)
    solve();

    return 0;

}
