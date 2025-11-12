#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a, int b) { return a > b; }
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m, r;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    	cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1, j = 1, o = 1;
	while(a[o] != r) {
		if(j % 2 == 0) i == 1? j++:i--;
		else i == n? j++:i++;
		o++;
	}
	cout << j << ' ' << i << '\n';
    return 0;
}
//rp++
