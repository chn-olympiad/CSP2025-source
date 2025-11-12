#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct Node {
	string u, v;
}a[N];
int main () {
	freopen("replace.in", "w", stdin);
	freopen("replace.out", "r", stdout);
	int n, q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i].u >> a[i].v;
	}
	while(q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int ls1 = s1.size(), ls2 = s2.size();
		if (ls1 != ls2) {
			cout << 0 << endl;
			continue;
		}
		for (int i=1; i<=n; i++) {
			int l = a[i].u.size();
			string s3;
			for(int j=0; j<ls1-l+1; j++) {
				for(k=0; k<j; k++) {
					s3[++tot] = s1[k];
				}
			}
			if(s3 == a[i].u) {
				
			}
		}
		
	}
	return 0;
}
