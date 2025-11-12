#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int n, m, id, px, py;
int a[1005];

bool cmp(int a, int b){
	return a > b;
}

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++) cin >> a[i];
	id = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 1;i <= n * m;i ++) if(a[i] == id) {id = i;break;}
	px = (id - 1) / n + 1;
	int t = (id - 1) % n + 1;
	if(px & 1) py = t;
	else py = (n - t + 1);
	cout << px << " " << py;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
