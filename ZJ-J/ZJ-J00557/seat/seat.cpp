#include <bits/stdc++.h>
using namespace std;

struct str{
	long long x,f;
}a[114];

bool cmp(str x,str y){
	return x.x > y.x;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	a[1].f = 1;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i].x;
	}
	sort(a + 1,a + n * m + 1,cmp);
	for (long long i = 1;i <= m;i++){
		if (i % 2 == 1){
			for (long long j = 1;j <= n;j++){
				if (a[(i - 1) * n + j].f == 1){
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		}
		else{
			for (long long j = n;j >= 1;j--){
				if (a[(i - 1) * n + j].f == 1){
					cout << i << ' ' << (n - j + 1) << endl;
					return 0;
				}
			}
		}
	}
	//cout << "error" << endl;
	return 0;
}
