#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110, mod = 998244353;

int n, m;
char ch;
int a[N], s[N], c[N];

signed main(){
	cin.tie(0) -> sync_with_stdio(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> ch;
		s[i] = (ch == '1');
	}
	for(int i = 1; i <= n; i++)  cin >> c[i];
	
	for(int i = 1; i <= n; i++)  a[i] = i;
	int ans = 0;
	do{
		int gu = 0;
		for(int i = 1; i <= n; i++){
			if(gu >= c[a[i]] || s[i] == 0)  gu++;
		}
		if(n - gu >= m)  ans++;
	}while(next_permutation(a + 1, a + n + 1));
	cout << ans;
	return 0;
}
/*
发现假如某个社团人数大于 n/2，即使把多于 n / 2 的人全部挪到另一个社团也是可以满足的
只需要记录每个人最大值和次大值的差，再按需分配人 
*/
