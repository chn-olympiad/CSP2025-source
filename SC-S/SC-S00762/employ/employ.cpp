#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n,m,p[510],c[510],ans;
bool b[510],flag;
string s;
void dfs(int i){
	if(i > n){
		long long jl = 0,sl = 0;
		for(int j = 1; j <= n; ++j){
			if(s[j - 1] == '0')jl++;
			else{
				if(jl >= c[p[j]])jl++;
				else sl++;
			}
		}
		if(sl >= m)ans = (ans + 1) % mod;
		return;
	}
	for(int j = 1; j <= n; ++j){
		if(b[j])continue;
		b[j] = true;
		p[i] = j;
		dfs(i + 1);
		b[j] = false;
		p[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i)cin >> c[i];
	dfs(1);
	cout << ans % mod;
	return 0;
}