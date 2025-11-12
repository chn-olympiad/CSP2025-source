#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

typedef long long ll;
typedef double db;

typedef vector <int> vi; 

int n, k, a[500010], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int x = 1;
	for (int i = 1; i <= n && x; i++) 
	    if (a[i] != 1)
	        x = 0;
	if (x == 1) {
		cout << (k == 1 ? n : n / 2) << endl;
		return 0;
    }
	
	x = 1;
	for (int i = 1; i <= n; i++)
	    if (a[i] > 1)
	        x = 0;
	if (x == 1) {
		if (k == 0) {
			for (int i = 1; i <= n; ) 
				if (a[i] == 0)
				    ++ans, ++i;
				else if (i + 1 <= n && a[i] == a[i + 1] && a[i] == 1)
				    ++ans, ++i, ++i;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1)
				    ++ans;   
			}
		}
		
		cout << ans << endl;
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
	    for (int j = i; j <= n; j++) {
	    	bool ok = 1; int x = 0;
	    	
			for (int l = i; l <= j; l++)
			    x ^= a[l];
			if (x == k)
		        ++ans,
		    cout << i << sp << j << endl;
		}
	
	cout << ans << endl; 
	return 0;
} 
