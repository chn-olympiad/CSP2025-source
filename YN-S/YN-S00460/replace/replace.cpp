#include <iostream>
using namespace std;
int n, q, q1, q2, ans;
int a[3][200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		
		string s1, s2;
		cin >> s1 >> s2;
		a[0][i] = size(s1);
		
		for (int k = 1; k <= size(s1); k++) {
			
			if (s1[k] == 'b')
				a[1][i] = k;
			
			if (s2[k] == 'b')
				a[2][i] = k;
		}
	}
	
	while (q--) {
		string t1, t2;
		
		for (int k = 1; k <= size(t1); k++) {
			
			if (t1[k] == 'b')
				q1 = k;
			
			if (t2[k] == 'b')
				q2 = k;
		}
		
		for (int i = 1; i <= n; i++) {
			
			if (a[0][i] <= size(t1)) {
				if (a[1][i] == q1 && a[2][i] == q2)
					ans++;
			}
		}
		
		cout << ans<<endl;
		
	}
	
}



