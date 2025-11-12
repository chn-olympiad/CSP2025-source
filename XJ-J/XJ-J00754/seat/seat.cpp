#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

typedef long long ll;
typedef double db;

typedef vector <int> vi; 

int a[10000], n, m, k;

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	k = n * m;
	for (int i = 1; i <= k; i++)
	    cin >> a[i];
	
	int s = a[1], t = 0;
	sort(a + 1, a + k + 1, cmp);
	
	for (int i = 1; i <= k; i++)
	    if (a[i] == s)
	        t = i;
	
	int y = (t - 1) / n + 1, x = t % n;
	if (x == 0)
	    x = n;
	
	if (y % 2 == 0)
	    x = n - x + 1;

	cout << y << sp << x << endl; 

	return 0;
} 
