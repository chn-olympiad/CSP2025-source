#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define fi first
#define se second
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(y);x--)
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define tomx(x,y) x=max(x,y)
#define tomn(x,y) x=min(x,y)
#define pof pop_front
#define ull unsigned long long
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
using namespace std;
int n,m;
#define N 505
string s;
int c[N];
namespace sub1{
	bool check(){
		return n<=18;
	}
	int f[(1<<18)+2][20];
	void solve(){
		f[0][0]=1;
		rep(S,0,(1<<n)-1){
			int cd=1;
			rep(i,0,n-1) cd+=((S>>i)&1);
			rep(i,0,n){
				if(!f[S][i]) continue;
//				cerr<<"CD: "<<cd<<"\n";
//				cerr<<"f["<<(bitset<10>(S))<<"]["<<i<<"]="<<f[S][i]<<"\n";
				rep(j,1,n){
					int T=S|((1<<(j-1)));
					if(S==T) continue;
//					cerr<<"c["<<j<<"]="<<c[j]<<"\n";
//					cerr<<"I: "<<i<<",s[cd]="<<s[cd]<<"\n";
					if(i>=c[j]||s[cd]=='0'){
//						cerr<<"C!\n";
						(f[T][i+1]+=f[S][i])%=mod;
					}else{
						(f[T][i]+=f[S][i])%=mod;
					}
				}
			}
		}
		int ans=0;
		rep(i,m,n){
//			cerr<<"I: "<<i<<"\n";
//cerr<<"D:E "<<(1<<n)-1<<","<<n-i<<"\n";
			ans+=f[(1<<n)-1][n-i];
		} 
		cout<<ans%mod;
	}
}
namespace sub2{
	bool check(){
		return m==1;
	}
	int t[N];
	void solve(){
		rep(i,1,n) t[c[i]]++;
		rep(i,1,n) t[i]+=t[i-1];
		int yr=0;
		int res=1;
		rep(i,1,n){
			if(s[i]=='1'){
				(res*=max<int>(0,t[i-1]-yr))%=mod;
				yr++;
//				cerr<<"I="<<i<<","<<yr<<","<<i-1<<"\n";
			}
		}
//		cerr<<"YR: "<<yr<<"\n";
		rep(i,1,n){
			if(s[i]=='0'){
				(res*=n-yr)%=mod;
				yr++;
			}
		}
		int ans=1;
		rep(i,1,n) (ans*=i)%=mod;
		cout<<((ans-res)%mod+mod)%mod;
	}
}
namespace sub3{
	bool check(){
		return m==n;
	}
	int ac[N][N];
	int C(int n,int m){
		if(m>n||m<0) return 0;
		return ac[n][m];
	}
	int fac[N];
	void solve(){
		if(count(all(s),'0')){
			cout<<0;
			return;
		}
		if(count(allt(c,1,n+1),'0')){
			cout<<0;
			return;
		}
		int res=1;
		rep(i,1,n) (res*=i)%=mod;
		cout<<res;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	rep(i,1,n) cin>>c[i];
	s=" "+s;
	if(sub1::check()) sub1::solve();
	else if(sub2::check()) sub2::solve();
	else
	if(sub3::check()) sub3::solve();
}
/*
10 10
1111111111
1 1 4 2 1 2 1 4 3 3


*/
