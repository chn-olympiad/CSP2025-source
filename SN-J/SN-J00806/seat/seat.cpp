#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;

int n, m, a[N], t[15][15];
inline void dfs(int x, int y, int step){
	if(y > m) return ;
	t[x][y] = step;
//	cout << x << " " << y << "\n";
	int nx = x;
	if(y % 2 == 1) ++nx;
	else --nx;
	if(nx > n) dfs(n, y + 1, step + 1);
	else if(nx < 1) dfs(1, y + 1, step + 1);
	else dfs(nx, y, step + 1);
}
inline bool cmp(int x, int y){return x > y;}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int x = a[1], pos = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i] == x){
		pos = i;
		break;
	}
//	cout << pos << "\n";
	dfs(1, 1, 1);
//	for(int i = 1; i <= n; i++, cout << "\n")
//		for(int j = 1; j <= m; j++)
//			cout << t[i][j] << " ";
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(t[i][j] == pos){
				cout << j << " " << i;
				return 0;
			}
	return 0;
}
