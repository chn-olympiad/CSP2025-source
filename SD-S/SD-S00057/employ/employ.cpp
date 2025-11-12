#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
const int MOD = 988244353;
template<typename TY>
inline void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	s = x * f;
}
int n,m;
ll ans;
int c[N],p[N];
ll fac[N];
void init(){
	fac[0] = 1; 
	for(int i=1;i<=n;i++){
		fac[i] = fac[i-1] * i % MOD;
	}
	cout << fac[n];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n); read(m);
	string s;
	cin >> s;
	bool f = false;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='0'){
			f = true;
			break;
		}
	} 
	if(!f){
		init();
		return 0;
	}
	for(int i=1;i<=n;i++){
		read(c[i]); p[i] = i;
	}
	if(n <= 10){
		do{
			int num = 0 ,cnt = 0;
			for(int i=1;i<=n;i++){
				if(s[i-1] == '0' || cnt >= c[p[i]]){
					cnt++;
					continue;
				}
				else num++; 
			}
			if(num >= m){
				ans++; if(ans>=MOD) ans-=MOD;
			}
		}while(next_permutation(p+1,p+n+1));
	}
	if(ans) cout << ans % MOD;
	else cout << ans;
	return 0;
}
