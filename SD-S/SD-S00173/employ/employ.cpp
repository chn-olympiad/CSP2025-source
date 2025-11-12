#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=505;
int n,m,c[N],ans;
string s;
bool flag=1;
void dfs(int nw,int fl,int t) {
	if(nw==n+1) {
		if(n-fl>=m)++ans;
		return ;
	}
	for(int i=1; i<=n; ++i) {
		if(t>>(i-1)&1)continue;
		if(fl>=c[i]||s[nw]=='0') {
			dfs(nw+1,fl+1,t|(1<<(i-1)));
		} else {
			dfs(nw+1,fl,t|(1<<(i-1)));
		}
	}
}
int t[N];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1; i<=n; ++i) cin>>c[i];
	sort(c+1,c+1+n);
	if(n<=18) {
		//20 pts
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==n) {
		//4pts
		ans=1;
		for(int i=1; i<=n; ++i) {
			if(c[i]==0||s[i]=='0') {
				cout<<"0";
				return 0;
			}
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1) {
		//0pts it's WA.
		//buxiele
		int fac=1;
		for(int i=1; i<=n; ++i) ++t[c[i]],fac=fac*i%mod;
		ans=1;
		int cnt=t[0];
		for(int i=1; i<=n; ++i) {
			if(s[i]=='1') {
				ans=ans*(cnt-i+1)%mod;
				cnt+=t[i];
			}else{
				ans=ans*(n-i+1)%mod;
			}
		}
		cout<<(fac-ans+mod)%mod<<"\n";
	}
	return 0;
}
//2025.11.1 17:41 100+72+30+24=226
//Is it enough?? I am too vegetable.
//I think SD-S01020 is going to AK.
//芳园何青青 桃李正葱茏
//水中镧化九百钼 Mo900LA.H2O
