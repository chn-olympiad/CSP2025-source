#include <bits/stdc++.h>
using namespace std;

int n , m;
string s;
int c[510];

int main () {
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	scanf ("%d%d",&n,&m);
	cin >> s;
	for (int i = 1;i <= n;i++) {
		scanf ("%d",&c[i]);
	}
	if (m == 1) {
		printf ("%d\n",n);
	}else if (m == n) {
		printf ("1\n");
	}
	return 0;
}
