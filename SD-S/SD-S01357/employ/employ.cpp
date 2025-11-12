//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,z,y) for(int x=z;x>=y;--x)
#define qwq cout<<'\n'
#define exq exit(0)
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define pb push_back
using namespace std;
void IOS(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
}
void Document(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int n;
int m;
const int N=20;
const int M=(1<<18)+55;
const int mod=998244353;
int f[M][N];
int c[N];
string s;
void solve1(){
	f[0][0]=1;
	int mx=(1<<n)-1;
	rep(i,0,mx-1){
		int ct=0;
		rep(o,1,n) if(((i>>(o-1))&1)) ct++;
		rep(o,0,n){
			if(f[i][o]==0) continue;
			rep(p,1,n){
				if(((i>>(p-1))&1)) continue;
				int S=i+(1<<(p-1));
				if(ct-o<c[p]&&s[ct+1]=='1'){
					(f[S][o+1]+=f[i][o])%=mod;
				}
				else{
					(f[S][o]+=f[i][o])%=mod;
				}
			}
		}
	}
	int answer=0;
	rep(i,m,n){
		answer+=f[mx][i];
		answer%=mod;
	}
	cout<<answer;
}
main(){
	IOS();
	Document();
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	rep(i,1,n) cin>>c[i];
	if(n<=18) solve1();
	else cout<<0;
	return 0;
}
