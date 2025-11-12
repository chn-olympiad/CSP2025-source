#include <bits/stdc++.h>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n, q;

int main() {
	NOI("replace")
	cin >> n >> q;
	while (q--) {
		cout << rand() % n << endl;
	}
	return 0;
}
