//employ
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 1e3 + 10;
const int mod = 998244353;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}

int n, m;
char s[N];
ll f[200005][20];
int c[N];
int popcount( int x ){
	int res = 0;
	while(x){
		if( x&1 )res++;
		x >>= 1;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();m = read();
	cin >> (s+1);
	
	for( int i = 1 ; i <= n ; ++i )c[i] = read();
	f[0][0] = 1;
	for( int j = 1 ; j < (1<<n) ; ++j ){
		for( int k = 0 ; k < n ; ++k ){
			int state = j;
			if( state & (1<<k) ){
				for( int i = 0 ; i <= n ; ++i ){
					int pos = popcount(state);
					if( s[pos] == '0' ){
						if( i == 0 )f[state][i] = 0;
						else{
							f[state][i] += f[state - (1<<k)][i-1];
							f[state][i] %= mod;
						}
					}
					else{
						if( c[k+1] > i ){
							f[state][i] += f[state - (1<<k)][i];
							f[state][i] %= mod;
						}
						if( c[k+1] < i ){
							f[state][i] += f[state - (1<<k)][i-1];
							f[state][i] %= mod;
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for( int i = 0 ; i <= n - m ; ++i )ans = (ans + f[(1<<n)-1][i]) % mod;
	cout << ans << "\n";
	return 0;
}

