#include <bits/stdc++.h>
using namespace std;

int n,q;
struct asd {
	string a,b;
}s[200010];

int main () {
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	scanf ("%d%d",&n,&q);
	for (int i = 1;i <= n;i++) {
		cin >> s[i].a >> s[i].b;
	}
	for (;q--;) {
		int ans = 0;
		string aa,bb;
		cin >> aa >> bb;
		if (aa == bb) {
			ans++;
		}
		for (int i = 1;i <= n;i++) {
			if (s[i].a == bb) {
				ans++;
			}
			if (s[i].b == bb) {
				ans++;
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}
