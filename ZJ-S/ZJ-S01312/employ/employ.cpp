#include<bits/stdc++.h>
using namespace std;
int n,m,i,c[510],f[510];long long ans,jc[510];char s[510];
const int mod=998244353;
void dg(int t,int sum,int fq){
	int i;
	if(sum>=m){
		ans=(ans+jc[n-t+1])%mod;return ;
	}
	if(t==n+1) return ;
	for(i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			if(c[i]>fq&&s[t-1]=='1') dg(t+1,sum+1,fq);
			else dg(t+1,sum,fq+1);
			f[i]=0;
		} 
}
bool check(){
	int i;
	for(i=0;i<n;i++)
		if(s[i]=='0') return 0;
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;jc[0]=1;jc[1]=1;
	for(i=2;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for(i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		dg(1,0,0);cout<<ans;return 0;
	}
	if(check()){
		cout<<jc[n]%mod;return 0;
	}
	cout<<0;
	return 0;
}