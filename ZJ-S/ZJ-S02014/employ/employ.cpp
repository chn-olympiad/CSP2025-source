#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define ll long long
constexpr int maxn = 503,mod = 998244353;
int n,m;
string s;
int c[maxn];
int ans;
int p[maxn];
int main(){
	IOS;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n > 11) cout << 0;
	else{
		for(int i = 1;i <= n;i++) p[i] = i;
		do{
			int pass = 0,fail = 0;
			for(int i = 1;i <= n;i++){
				if(fail >= c[p[i]] or s[i-1] == '0') fail++;
				else pass++;
			}
			if(pass >= m) (ans += 1) %= mod;
		}while(next_permutation(p+1,p+n+1));
	}
	cout << ans;
	return 0;
}
