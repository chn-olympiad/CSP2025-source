#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m;
string s;
int c[505];
int a[505],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++) a[i] = i;
	bool A = 1;
	for(int i = 0;i < n;i++) if(s[i] == '0') A = 0;
	if(A){
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += (c[i] != 0);
		if(cnt != 0){
			ans = 1;
			for(int i = 2;i <= cnt;i++) ans = ans*i%mod;
		}
	}else{
		s = '@'+s;
//		int cnt = 0;
		do{
			int cntfail = 0,cntwin = 0;
			for(int i = 1;i <= n;i++){
				if(cntfail >= c[a[i]]){
					cntfail++;
					continue;
				}
				cntwin += (s[i] == '1');
				cntfail += (s[i] == '0');
			} 
			ans += (cntwin >= m);
//			cnt++;
		}while(next_permutation(a+1,a+1+n));
	}
	
	cout << ans%mod;
}

