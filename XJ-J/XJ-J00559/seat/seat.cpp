#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;

struct Info{
	int x;
	int pos;
} a[1010];

bool cmp(const Info &a, const Info &b){
	return a.x > b.x;
}

int main(){
	fropen("seat.in", "r", stdin);
	fropen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i].x, a[i].pos = i;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
		if(a[i].pos == 1){
			int p = i;
			int d = p / n;
			if(p % n == 0){
				if((p / n) & 1)
					cout << d << ' ' << n << '\n';
				else
					cout << d << ' ' << 1 << '\n';
			} else{
				cout << d + 1 << ' ';
				if((p / n + 1) & 1)
					cout << p % n;
				else
					cout << n - p % n + 1;
			}
		}
	return 0;
}
