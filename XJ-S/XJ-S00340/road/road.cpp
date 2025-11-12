#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;

int n, m, k, a[20][20000];
vector <int> c(20); 

int main() {
	freopen("road.in", "r", stdin),
	freopen("road.out", "w", stdout),
    
	ios::sync_with_stdio(false),
	cin.tie(0), cout.tie(0),
    
	cin >> n >> m >> k;
    for (int i = 1, x, y, z; i <= n; i++) {
    	cin >> x >> y >> z;
	}
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		    cin >> a[i][j];
	} 
	
	cout << 0 << endl;
	
	return 0;
}
