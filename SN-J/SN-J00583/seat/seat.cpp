#include <bits/stdc++.h>
#include <vector>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);

int main() {
	int n, m,s[10005];
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	for (int i = 0; i <= s[i]; i++) {
		if (s[1] == max(s[i], s[n * m])) {
			cout << 1 << " " << 1 << endl;
		} else if (s[1] == min(s[i], s[n * m])) {
				if(m % 2 == 0){
					cout << m << " " << 1 << endl;
					break;
				} else {
					cout << m << " " << n << endl;
					break;
			}
		}
		if(s[i] == s[1]){
			if(i == n + 1){
				cout << 2 << " " << n << endl;
			}	 
		}
	}
}
