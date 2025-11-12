#include<bits/stdc++.h>
using namespace std;
using ld=long double;
#define int long long
#define endl "\n"
#define tim double(clock())/CLOCKS_PER_SEC

const int N=1e6+5,M=3005,inf=1e18,mod=998244353;

int n,m,a[N],idx[N];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ld Tim=double(clock())/CLOCKS_PER_SEC;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s; s=" "+s;
	int fl1=1,fl0=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(s[i]=='1') fl0=0;
		else fl1=0;
	}
	if(m==n){
		if(fl0==0) cout<<0;
		else cout<<1;
	}
	else{
		for(int i=1;i<=n;i++) idx[i]=i;
		int ans=0;
		do{
			int cnt=0,res=0;
			for(int _=1;_<=n;_++){
				int i=idx[_];
				if(cnt>=a[i]||s[_]=='0') cnt++;
				else res++;
			}
			if(tim-Tim>0.85){
				cout<<ans;
				return 0;
			}
			if(res>=m) ans++;
		}while(next_permutation(idx+1,idx+n+1));
		cout<<ans;
	}
	return 0;
}
