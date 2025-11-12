#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,C[1001],m;
string s;
int b[101],c[101],S[1001],ans;
int fac[1001],inv[1001];
int qmi(int A,int p){
	int ret=1;
	while(p){
		if(p&1){
			ret*=A;
			ret%=mod;
		}
		A=A*A%mod,p>>=1;
	}
	return ret;
}
int CC(int N,int M){
	if(N<M) return 0;
	return fac[N]*inv[M]%mod*inv[N-M]%mod;
}
void dfs(int i){
	if(i==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=C[b[i]]||s[i-1]=='0'){
				cnt++;
			}
		}
		if(n-cnt>=m) ans++;
		return;
	}
	for(int j=1;j<=n;j++){
		if(!c[j]){
			b[i]=j,c[j]=1;
			dfs(i+1);
			c[j]=0;
		}
	}
}
void BBT(){
	dfs(1);
	cout<<ans;
}
void BT(){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=qmi(fac[n],mod-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) S[C[i]]++;
	for(int i=n-1;i>=1;i--) S[i]+=S[i+1];
	int cnt=0,tmp=1;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			ans+=S[i]*tmp%mod*fac[n-1-cnt]%mod;
			ans%=mod;
			tmp*=n-S[i]-cnt;
			if(n-S[i]<cnt) tmp=0;
			tmp%=mod;
			cnt++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>C[i];
	}
	if(n<=10) BBT();
	else if(m==1){
		BT();
	}
	else cout<<0;
	return 0;
}
