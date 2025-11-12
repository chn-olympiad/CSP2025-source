#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+5;

int T,n;
int a[N][5];
int b[N];
int ans;
int Club[4];

void solve() {
	n = ans = 0;
	memset(Club,0,sizeof(Club));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin >> n;
	for(int i = 1;i <= n;++i) for(int j = 1;j <= 3;++j) cin >> a[i][j];
	
	for(int i = 1;i <= n;++i) {
		int t = 1;
		for(int j = 2;j <= 3;++j) if(a[i][j] > a[i][t]) t = j;
		Club[t]++;
		ans += a[i][t];
	}
	
	int max_p = 1;
	for(int i = 1;i <= 3;++i) if(Club[i] > Club[max_p]) max_p = i;
	
	int s = 0;
	for(int i = 1;i <= n;++i) {
		int mp = 1;
		for(int j = 2;j <= 3;++j) if(a[i][j] > a[i][mp]) mp = j;
		if(mp != max_p) continue;
		int m = a[i][mp];
		a[i][mp] = -1;
		mp = 1;
		for(int j = 2;j <= 3;++j) if(a[i][j] > a[i][mp]) mp = j;
		b[++s] = m - a[i][mp];
	}
	
	sort(b+1,b+s+1);
	
	
	int t = 1;
	
	
	/*cout << "-=-=-=" << ans << '\n';
	for(int i = 1;i <= n;++i) {
		cout << b[i] << ' ';
	}
	cout << "=========\n";*/
	
	while(Club[max_p] > n/2) {
		ans -= b[t];
		++t;
		Club[max_p]--; 
	}
	cout << ans << '\n';
}

int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) solve();
	return 0;
}





/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/