#include<bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
int jc[505],n,m,ans,vis[505],a[505],chu[505];
string s;
void dfs(int day,int cnt){
	if(day == n){
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			chu[day] = i;
			if(a[i] > day - cnt && s[day] == '1') dfs(day + 1,cnt + 1);
			else dfs(day + 1,cnt);
			vis[i] = 0;
		}
	} 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0] = 1;
	for(int i = 1; i <= 504; i++) jc[i] = jc[i - 1] * i % mod;
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		int pos = -1,s1 = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1') pos = i;
		}
		if(pos == -1) cout << 0;
		else{
			for(int i = 1; i <= n; i++){
				if(a[i] > pos) s1++;
			}
			cout << (jc[s1] + jc[n - s1]) % mod;
		}
		return 0;
	}else{
		dfs(0,0);
		cout << ans;
	}
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
