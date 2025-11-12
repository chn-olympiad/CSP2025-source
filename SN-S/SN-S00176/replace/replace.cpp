#include <bits/stdc++.h>
#define maxn 10010
#define maxm 1000100
#define ll long long
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define int long long
#define lowbit(x) (x & (-x))
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fir first
#define mod 998244353
#define sec second
using namespace std;
int n,q;
int T = 1;
string s[2][maxn],t[2][maxn];
int l[2][maxn];
vector <int> v[2][maxn];
int base[200010];
int has(string x){
	int now = 0;
	int len = x.length();
	for(int i = 0;i <= len - 1;i++){
		now = now * 28ll % mod + (x[i] - 'a'+ 1);
		now %= mod;
	}
	return now;
}
void has2(int x){
	int len = t[0][x].length(),now = 0;
	for(int i = 0;i <= len - 1;i++){
		now = now * 28ll % mod + (t[0][x][i] - 'a' + 1) % mod;
		now %= mod;
		v[0][x].push_back(now);
	}
	now = 0;
	for(int i = 0;i <= len - 1;i++){
		now = now * 28ll % mod + (t[1][x][i] - 'a' + 1) % mod;
		now %= mod;
		v[1][x].push_back(now);
	}
}
int get(int ty,int L,int R,int now){
	int lsum = 0;
	if(R <L){
		return 0;
	}
//	cout <<L << ' ' << R << endl;
//	if(ty == 0){
		if(L != 0){
			lsum = v[ty][now][L - 1];
		}
//		cout <<lsum * base[R - L + 1]<< " " << v[ty][now][R]<< endl;
		return ((v[ty][now][R] - (lsum * base[R - L + 1] % mod) % mod) + mod) % mod;
//	}else{
//		if(L != 0){
//			lsum = r[ty][L - 1];
//		}
//		return (r[ty][R] - (lsum * base[R - L] % mod) + mod) % mod;
//	}
	
}
void solve(){
	base[0] = 1;
	for(int i = 1;i <= 200000;i++){
		base[i] = base[i - 1] * 28 % mod;
	}
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[0][i] >> s[1][i];
		l[0][i] = has(s[0][i]),l[1][i] = has(s[1][i]);
//		cout << l[0][i] << ' ' << l[1][i] << endl;
	}
	for(int j = 1;j <= q;j++){
		cin >> t[0][j] >> t[1][j];
		has2(j);
		int ans = 0;
		for(int i = 1;i <= n;i++){
//			cout <<i <<endl;
			for(int k = 0;k <= (int)t[0][j].length() - (int)s[0][i].length();k++){
				if(l[0][i] == get(0,k,k + s[0][i].length() - 1,j) && l[1][i] == get(1,k,s[1][i].length() + k - 1,j) && get(0,0,k - 1,j) == get(1,0,k - 1,j) && get(0,k + s[0][i].length(),t[0][j].length() - 1,j) == get(1,k + s[1][i].length(),t[0][j].length() - 1,j)){
					ans++;
//					cout << k <<" "<<k + s[0][i].length() - 1<<endl;
				}
			}
		}
		cout<< ans << endl;
	}
}
signed main(){
//	cin >> T;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
//    IO;
    while(T--){
    	solve();
	}	
	return 0;
}
