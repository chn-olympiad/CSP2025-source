#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,m,ans,l,k = 1,cnt,f,p,mn = 1000;
string s;
int c[505],vis[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>> n >> m >> s;
	l = s.length() - 1;
	for(int i = 1;i <= n;i++){
		cin>> c[i];
		vis[c[i]]++;
		if(s[i - 1] == '0') k = 0;
		if(c[i] != 0) mn = min(mn,c[i]);
	}
	p = vis[0];
	if(k == 0){
		if(m > 1){
			ans = 1;
			k = 0;
			for(int i = 0;i <= l;i++){
				if(s[i] == '0'){
					k++;
					if(vis[k] < cnt){
						p += cnt;
						for(int i = cnt;i >= 2;i--){
							f++;
							ans = (ans * (i % mod)) % mod;
						}
						cnt = 0;
						continue;
					}
					p += vis[k];
					for(int i = vis[k];i >= cnt;i--){
						f++;
						ans = (ans * (i % mod)) % mod;
					}
					cnt = 0;
				}
				else cnt++;
			}
			for(int i = n - p;i >= cnt;i--){
				f++;
				ans = (ans * (i % mod)) % mod;
			}
			if(f >= m) cout<< ans;
			else cout<< 0;
			return 0;
		}
		for(int i = 0;i <= l;i++){
			if(s[i] == 1){
				k = i;
				break;
			}
		}
		for(int i = 1;i <= n;i++) if(c[i] > k) ans = 1;
		for(int i = n - 1;i > 0;i--){
			ans = (ans * (i % mod)) % mod;
		}
		cout<< ans;
	}
	else{
		ans = 1;
		p = max(0,vis[0] - mn + 1);
		for(int i = n - p;i > 0;i--){
			ans = (ans * (i % mod)) % mod;
		}
		int ans1 = 1;
		for(int i = p;i > 0;i--){
			ans1 = (ans1 * (i % mod)) % mod;
		}
		cout<< (ans * ans1) % mod;
	}
	return 0;
}
