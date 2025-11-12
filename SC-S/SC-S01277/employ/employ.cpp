#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define db double
#define i128 __int128
#define ull unsigned long long
#define ui unsigned int

const int N=500;
const ll mod=998244353;
void pls(ll &x,ll y){
	x+=y;
	if(x>=mod) x-=mod;
}
int n,m,s[N+10];
ll cnt[N+10];
ll fac[N+10];
ll f[2][N+10][N+10];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=n;i>=1;i--) cnt[i]+=cnt[i+1];
	
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ll ans=0;
	for(int i=1;i<=n;i++) f[0][0][i]=fac[n-i];
	for(int j=0;j<n;j++){
		int p=(j&1),q=(p^1);
		for(int k=0;k<=n;k++)
			for(int l=0;l<=n;l++)
				f[q][k][l]=0;
		for(int k=0;k<=n;k++)
			for(int l=0;l<=n;l++){
				if(s[j+1]==0){
					pls(f[q][k+1][l],f[p][k][l]);
				}
				else{
					pls(f[q][k+1][l],f[p][k][l]);//not choose
					pls(f[q][k+1][l-1],mod-(cnt[k+1]-l+1)*f[p][k][l]%mod);//count but not choose.
					if(l>0) pls(f[q][k][l-1],(cnt[k+1]-l+1)*f[p][k][l]%mod);//choose and also count.
				}
			}
	}
	ll res=0;
	for(int k=0;k<=n-m;k++) pls(res,f[n&1][k][0]);
	cout<<res<<'\n';
    return 0;
}
/*
W_init [,14:41]
T_C [15:44,15:54](AC-auto....)
T_D [15:54,16:06]
W_D_brute [,16:19]
C_D_brute [,16:26](e.g.1),[,16:44]
T+W_D_2 [,16:59]
C_n^4 [,17:07]
T+W_100 [,17:11]
C_MLE [,17:14]
is this really CSP-S T4?
ok,only T3 left....

fc employ1.ans employ.out

ulimit -s 1024000
g++ test.cpp -o test -std=c++14 -O2 -static -Wall -Wshadow -Wextra
g++ test.cpp -o test -std=c++14 -O2 -Wall -Wshadow -Wextra -fsanitize=address,undefined
./test 
*/