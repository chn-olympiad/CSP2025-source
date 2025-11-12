#include<bits/stdc++.h>
#define f(i , x , y) for(int i = (x); i <= (y); ++ i)
#define int long long
using namespace std;
inline int read(){
	int x = 0 , f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	return x * f;
}
const int N = 500 + 7;
constexpr int P = 998244353;
int a[N] , p[N] , n , m;
namespace Solution{
	inline void solve(){
		n = read() , m = read();
		string s;
		cin >> s;
		f(i , 1, n){
			 a[i] = read() , p[i] = i; //cout << a[i] << '\n';
		}
		if(m == n){
			int x=  0;
			f(i , 1, n){
				if(s[i - 1] == '0' || a[i] == 0) ++ x;
			}
			if(x) cout << 0 << '\n';
			else {
				int ans = 1;
				f(i , 1, n) ans *= i , ans %= P;
				cout << ans << '\n';
			}
			return ;
		}
		{
			int ans = 0;
			do{
				int cnt = 0; //ËÀµÄÈË
				f(i , 1 , n){
					int x = p[i];
					if(a[x] <= cnt){
						++ cnt;
						continue;
					}
					if(s[i - 1] == '0') ++ cnt;
				} 
				if(cnt <= (n - m)) ++ ans;
			}while(next_permutation(p + 1, p + n + 1));
			cout << ans % P << '\n';
			return ;
		}
		
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T = 1;
	while(T --) Solution :: solve();
	return 0;
}

