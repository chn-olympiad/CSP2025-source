#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 100010;

int a[N], b[N], c[N], d[N][3], e[N], f[N], g[N];

bool cmp(int i, int j){
	return i > j;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t --){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		memset(e, 0, sizeof(e));
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] == b[i] && a[i] > c[i]) d[i][0] = 0, d[i][1] = 1;
			else if(b[i] == c[i] && b[i] > a[i]) d[i][0] = 0, d[i][1] = 2;
			else if(a[i] == c[i] && a[i] > b[i]) d[i][0] = 0, d[i][1] = 1;
			else if(a[i] > b[i] && a[i] > c[i] && b[i] > c[i]) d[i][0] = a[i] - b[i], d[i][1] = 1;
			else if(a[i] > b[i] && a[i] > c[i]) d[i][0] = a[i] - c[i], d[i][1] = 1;
			else if(b[i] > a[i] && b[i] > c[i] && a[i] > c[i]) d[i][0] = b[i] - a[i], d[i][1] = 2;
			else if(b[i] > a[i] && b[i] > c[i]) d[i][0] = b[i] - c[i], d[i][1] = 2;
			else if(c[i] > b[i] && c[i] > a[i] && a[i] > b[i]) d[i][0] = c[i] - a[i], d[i][1] = 3;
			else d[i][0] = c[i] - b[i], d[i][1] = 3;
        }
		int A = 0, B = 0, C = 0, ans = 0;
		for(int i = 1; i <= n; i ++){
			if(d[i][1] == 1) A ++, e[A] = d[i][0], ans += a[i];
			else if(d[i][1] == 2) B ++, f[B] = d[i][0], ans += b[i];
			else C ++, g[C] = d[i][0], ans += c[i];
		} 
		
		if(A > n / 2){
		    sort(e + 1, e + A + 1, cmp);
		    for(int i = A; i > n / 2; i --)
		    	ans -= e[i];
		}
		else if(B > n / 2){
		    sort(f + 1, f + B + 1, cmp);
		    for(int i = B; i > n / 2; i --)
		    	ans -= f[i];
		}
		else if(C > n / 2){
		    sort(g + 1, g + C + 1, cmp);
		    for(int i = C; i > n / 2; i --)
		    	ans -= g[i];
		}
		cout << ans << endl;
	}
}
