#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;

int n, q;
pair <string, string> r[200010], t;

int main() {
	freopen("replace.in", "r", stdin),
	freopen("replace.out", "w", stdout),
    
    ios::sync_with_stdio(false),
    cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	    cin >> r[i].first >> r[i].second;
	    
	for (; q--; cout << 0 << endl) {
		cin >> t.first >> t.second;
	}
	
	return 0;
}
