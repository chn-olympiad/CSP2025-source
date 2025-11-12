#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=20,mod=998244353;

int n,m,c[N];

string s;

ll dp[1<<18][N];

inline int get_num(int num){
	int res=0;
	while(num){
		if(num&1) res++;
		num>>=1;
	}
	return res;
}

int main(){
	#ifndef Klein
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s; s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>18){
		cout<<0;
		return 0;
	} 
	dp[0][0]=1;
	for(int l=0;l<(1<<n)-1;l++){
		int tot=get_num(l);
		for(int j=0;j<=tot;j++){
			if(!dp[l][j]) continue;
			for(int k=1;k<=n;k++){
				if((l>>(k-1))&1) continue;
				if(s[tot+1]=='0'||tot-j>=c[k]) (dp[l|(1<<(k-1))][j]+=dp[l][j])%=mod;
				else (dp[l|(1<<(k-1))][j+1]+=dp[l][j])%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++) (ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}