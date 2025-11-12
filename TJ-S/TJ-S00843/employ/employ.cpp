#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=1005;

LL n,m;
string s;
LL c[N];
LL tmp[N];
bool b[N];
LL ans;
const LL MOD=998244353;

void dfs(LL x){
	if(x==n+1){
		LL cnt=0,sum=0;
		for(LL i=1;i<=n;i++) {
			if(s[i]=='0' || cnt>=c[tmp[i]]) cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
		return ;
	}
	for(LL i=1;i<=n;i++) {
		if(b[i]==false){
			b[i]=true;
			tmp[x]=i;
			dfs(x+1);
			b[i]=false;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	LL ls=s.size();
	s=" "+s;
	for(LL i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else {
		LL cnt=0;
		for(LL i=1;i<=n;i++){
			if(s[i]=='1') cnt++;
		}
		if(cnt==ls) {
			ans=1;
			int tmp=n;
			for(int i=1;i<=n;i++) {
				if(c[i]==0) tmp--;
			}
			for(LL i=1;i<=tmp;i++) ans=ans*i%MOD;
			cout<<ans%MOD;
		}
		else cout<<0;
	}
	return 0;
}
