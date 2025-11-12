#include<bits/stdc++.h>
#define f(i , x , y) for(int i = (x); i <= (y); ++ i)
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
int n; 
const int N = 1e5 + 7;
int a[N] , b[N] , c[N];
namespace Solution{
	inline void solve(){
		n = read();
		f(i , 1, n) a[i] = read() , b[i] = read()  , c[i] = read();
		int x = 0 , y = 0 , z = 0;
		f(i , 1, n){
			if(a[i] >= b[i] && a[i] >= c[i]) ++ x;
			else if(b[i] >= a[i] && b[i] >= c[i]) ++ y;
			else ++ z;
		}
		int t = n / 2;
		if(x <= t & y <= t && z <= t){
			int ans = 0;
			f(i , 1 , n) ans += max(a[i] , max(b[i] , c[i]));
			cout << ans << '\n';
			return ;
		}
		int ans = 0;
		vector<int> v;
		f(i , 1 , n){
			if(x > t && a[i] >= max(b[i] , c[i])) v . push_back(a[i] - max(b[i] , c[i]));
			else if(y > t && b[i] >= max(a[i] , b[i])) v . push_back(b[i] - max(a[i] , c[i]));
			else if(z > t && c[i] >= max(a[i] , b[i])) v . push_back(c[i] - max(a[i] , b[i]));
			ans += max(a[i] , max(b[i] , c[i])); 
		} 
		sort(v . begin() , v . end() , greater<int>());
		while(v . size() > t){
			ans -= v . back();
			v . pop_back();
		}
		cout << ans <<'\n';
	}  
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while(T --) Solution :: solve();
	return 0;
}

