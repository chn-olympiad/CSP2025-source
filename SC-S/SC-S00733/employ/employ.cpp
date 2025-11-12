#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 520,mod = 998244353;
int n,m,c[N],p[N];ll ans;
char S[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin >> n >> m >> (S+1);
	for(int i = 1;i <= n;++i) cin >> c[i],p[i] = i;
	if(n <= 10){
		do{
			int s = 0;
			for(int i = 1,L = 0;i <= n;++i){
				if(S[i] == '0') ++L;
				else{
					if(c[p[i]] <= L) ++L;
					else ++s;
				}
			}ans += (s >= m);
		}while(next_permutation(p+1,p+1+n));
		cout << ans%mod << "\n";		
	}else{
		ans = 1;
		for(int i = 1;i <= n;++i) (ans *= i) %= mod;
		cout << ans << "\n";
	}
	return 0;
}