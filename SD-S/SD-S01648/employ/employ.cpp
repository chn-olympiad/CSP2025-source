#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n,m,ans,cntn = 0;
long long a[502],c[502],jie[502];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	jie[1] = jie[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] == 0)cntn++;
		a[i] = i;	
		jie[i] = (jie[i-1] * i)%mod; 
	}
	if(n <=18){
		int tmp = 0,cnt = 0;
		do{
			tmp = cnt = 0;
			for(int i = 1; i <=n; i++){
				if(cnt >= c[a[i]]){
					cnt++;
					continue;
				}
					
				if(s[i-1]=='0')
					cnt++;
				else
					tmp++;
			}
			if(tmp >= m)ans = (ans + 1) % mod;
		}
		while(next_permutation(a+1,a+1+n));
		cout << ans;
		return 0;
	}
	if( m == n){
		if(cntn > 0){
			cout << 0;
			return 0;
		}
		
		bool is = 0;
		for(int i = 1; i <= n; i++)
			if(s[i-1] == '0'){
				is = 1;
				break;
			}
		if(is)cout << 0;
		else cout << jie[n];
		return 0;
	}
	if( m == 1){
		bool is = 0;
		for(int i = 1; i <= n; i++)
			if(s[i-1] == '1'){
				is = 1;
				break;
			}
		if(is)cout << jie[n - cntn];
		else cout << 0;
		return 0;
	}
	long long cot = 1;
	for(int i = m; i <= n; i++){
		
	}
	return 0;
}

