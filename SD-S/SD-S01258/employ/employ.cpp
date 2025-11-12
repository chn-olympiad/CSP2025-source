#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=507;
const int mod=998244353;

int a[N],c[N],s[N];
int n,m;
char ch;

void solve(){
	iota(a+1,a+n+1,1);
	int ans=0;
	while(1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=cnt){
				cnt++;
				continue;
			}
			if(!s[i]) cnt++;
		}
		if(n-cnt>=m) ans++;
		if(!next_permutation(a+1,a+n+1)) break;
	}
	cout<<ans;
}

void solve1(){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag=false,flag1=false;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
		if(!s[i]) flag=true;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]) flag1=true;
	}
	if(n<=10) solve();
	else if(flag) solve1();
	else if(m==n){
		if(flag||flag1) puts("0");
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
		}
	} else if(m==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	} else {
		puts("0");
	}
	return 0;
}
