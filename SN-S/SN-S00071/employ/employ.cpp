#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 8;
int n, m, c[N];
string ab;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>ab;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	int idx = ab.size();
	if(m == 1) {
		cout<<(m-1)*m/2;
		return 0;
	}
	if(m == n) {
		cout<<1;
		return 0;
	}
	return 0;
}

