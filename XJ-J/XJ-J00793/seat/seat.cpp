#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e2 + 10;

int n, m, a[N];

bool cmp(int p, int q){
	return p > q;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	int a1 = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 1; i <= n * m; i ++){
		if(a1 == a[i]){
			int ans = i % n + 1;
			int sum = i / n;
			if(i <= n){
				cout << 1 << " " << i;
				return 0;
			}else if(ans == 0){
				cout << sum << " " << n;
				return 0;
			}else if(sum % 2 == 1){
				cout << sum + 1 << " " << ans;
				return 0;
			} else if (sum % 2 == 0){
				cout << sum + 1 << " " << n - ans;
				return 0;
			}
		}
	}
	return 0;
}

