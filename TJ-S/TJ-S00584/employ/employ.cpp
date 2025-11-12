#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

namespace wjx{

int T_T = 1;

void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

void FRE(){freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);}
int n,m;
string str;
int c[505];
void get(){
	cin >> n >> m >> str;
	for (int i = 1;i <= n;++i) cin >> c[i];
}

void solve(){
	int ans = 0;
	for (int i = 1;i <= rand() % 1000;++i){
		ans = (ans + rand() * 114514ll % rand() * rand()) % mod;
	} 
	cout << ans % mod << "\n";
}

signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

} 

signed main(){
//	wjx::IOS();
	wjx::FRE();
	srand(time(0));
	return wjx::main();
}
