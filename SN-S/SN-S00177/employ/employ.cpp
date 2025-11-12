#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;
#define int long long
const int mod=998244353 ;
int read() {
	char c;int t=1;
	while(1) {
		c=getchar();
		if(c>='0'&&c<='9') break ; 
	}
	int s=c-'0';
	while(1) {
		c=getchar() ;
		if(c<'0'||c>'9') break ;
		s=s*10+c-'0';
	}
	return s ;
}
int n,m ;
string s ;
int c[1000005] ;
int fck[1000005] ;
int f[1<<19][19] ;
void work() {
	cin>>n>>m ;
	cin>>s ;s=" "+s ;
	for(int i=1;i<=n;i++) cin>>c[i] ;
	if(n<=10) {
		vector<int> p(15) ;
		for(int i=1;i<=n;i++) p[i]=i ;
		int ans=0 ;
		do {
			int cnt=0 ;
			int res=0 ;
			for(int i=1;i<=n;i++) if(s[i]=='1'&&cnt<c[p[i]]) res++ ;else cnt++ ;
			if(res>=m) ans++ ;
		} while(next_permutation(p.begin()+1,p.begin()+n+1)) ;
		cout<<ans%mod;
		return ;
	}
	if(n<=18) {
//		for(int i=1;i<=n;i++) if(c[i]) f[1<<i][1]=
f[0][0]=1;
int ans=0 ;
		for(int i=0;i<1<<n;i++) {
			for(int j=0;j<=n;j++) {
//				if(i<=10) cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
				if(!f[i][j]) continue ;
				int cnt=__builtin_popcount(i) ;
				if(i==(1<<n)-1&&j>=m) {
					ans+=f[i][j];
					ans%=mod ;
				}
				for(int k=1;k<=n;k++){
					if(!(i&(1<<k-1))) {
						if(c[k]>j&&s[cnt+1]=='1') f[i|(1<<k-1)][j+1]+=f[i][j],f[i|(1<<k-1)][j+1]%=mod ;
						else f[i|(1<<k-1)][j]+=f[i][j],f[i|(1<<k-1)][j]%=mod ;
					}
				}
			}
		}
		cout<<ans ;
		return ;
	}
	int cnt=0 ;
	for(int i=1;i<=n;i++) if(s[i]=='0') cnt++ ;
	if(!cnt) {
		int sum=0 ;
		for(int i=1;i<=n;i++) if(c[i]!=0) sum++ ;
		if(sum>=m) cout<<fck[n] ;
		else cout<<0 ;
		return ;
	}
	if(m==n) {
		if(cnt) cout<<0 ;
		else {
			cout<<fck[n] ;
		}
		return ;
	}
}
signed main() {
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
//cin>>TT ;
fck[0]=1 ;for(int i=1;i<=1000000;i++) fck[i]=fck[i-1]*i%mod ;
int TT=1 ;
while(TT--) {work() ;}
	
	
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
