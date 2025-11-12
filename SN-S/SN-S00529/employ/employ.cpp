#include<bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define mid(l, r) ((l + r) >> 1)
#define pii pair<int, int>
#define sec second
#define fir first
using namespace std;
typedef long long ll;
const int N = 505, mod = 998244353;

int n, m;
string s;
int c[N], sum[N], a[N];
ll frac[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	frac[0] = 1;
	for(int i = 1; i <= n; i++) a[i] = i, frac[i] = frac[i - 1] * i % mod;
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (!(s[i - 1] - '0'));
	if(m == n){
		bool f = 1;
		for(int i = 1; i <= n; i++) if(c[i] == 0 || s[i - 1] == '0'){
			f = 0; break;
		} 
		if(!f) cout << 0;
		else cout << frac[n];
	}
	else if(sum[n] == 0){
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(c[i] == 0) ++cnt;
		if(n - cnt < m) cout << 0;
		else{
			
		}
	}
	else if(n <= 18){
		int cnt = 0;
		do{
			int p = 0, ans = 0;
			for(int i = 1; i <= n; i++){
//				cout << a[i] << " ";
				if(c[a[i]] <= p || s[i - 1] == '0') ++p;
				else ++ans;
			}
//			cout << "\n";
			if(ans >= m) ++cnt;
		}while(next_permutation(a + 1, a + n + 1));
		cout << cnt;
	}else{
		cout << frac[n];
	}
	return 0;
}

