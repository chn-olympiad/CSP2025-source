#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void read(int &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
void read(ll &x){
	x=0;ll sign=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')sign=-1;
		ch=getchar();
	}
	while((ch>='0'&&ch<='9')){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=x*sign;
}
const int N=3e5+5;
const int mod=998244353;
int n,m;
char s[N];
int p[N],cc[N],fac[N],inv_fac[N],c[N],p1[N];
ll C(ll n,ll m){
	if(n<m)return 0;
	return fac[n]*inv_fac[m]*inv_fac[n-m];
}
ll ksm(ll x,ll y,ll z){
	ll ans=1;
	while(y){
		if(y&1)ans=ans*x%z;
		x=x*x%z;
		y>>=1;
	}
	return ans;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	double ctt=clock();
	read(n);read(m);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv_fac[n]=ksm(fac[n],mod-2,mod);
	for(int i=n-1;i>=1;i--){
		inv_fac[i]=inv_fac[i+1]*(i+1)%mod; 
	}
	for(int i=1;i<=n;i++)scanf("%c",&s[i]);
	for(int i=1;i<=n;i++)read(c[i]),p[c[i]]++;
	for(int i=0;i<=n;i++)p1[i]=p[i];
	for(int i=n;i>=1;i--)p[i]+=p[i+1];
	if(n<=10){
		ll ans=0;
		for(int i=1;i<=n;i++)cc[i]=i;
		do{
			int ans1=0,p1=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'&&ans1<c[cc[i]])p1++;
				else ans1++;
			}
			if(p1>=m)ans++;
		}while(next_permutation(cc+1,cc+n+1));
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				return 0;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0)ans++;
		}
		if(ans>=1)puts("0");
		else{
			printf("%lld\n",fac[n]);
		}
	}
	//cerr<<(double)((clock()-ctt)/CLOCKS_PER_SEC)<<"s";
	return 0;
}
