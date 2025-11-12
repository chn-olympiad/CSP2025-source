#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
constexpr int N=500+10,mod=998244353;using namespace std;void solve();
int n,m,c[N];string s;
namespace solve1{
	bool check(){return n<=10;}
	int per[N];
	void solve(){
		forUp(i,1,n)per[i]=i;
		int ans=0;
		while(true){
			int cnt=0;
			forUp(i,1,n)if(s[i]=='0'||cnt>=c[per[i]])++cnt;
			if(n-cnt>=m)ans=(ans+1)%mod;
			if(!next_permutation(per+1,per+n+1))break;
		}
		cout<<ans<<'\n';
	}
}//1,2
namespace solve2{
	bool check(){return n==m;}
	void solve(){
		int ans=1;
		forUp(i,1,n)ans=1ll*ans*i%mod;
		forUp(i,1,n)if(s[i]=='0'||c[i]==0)ans=0;
		cout<<ans<<'\n';
	}
}//15
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=" "+s;
	forUp(i,1,n)cin>>c[i];
	if(solve1::check())solve1::solve();
	else if(solve2::check())solve2::solve();
	return 0;
}