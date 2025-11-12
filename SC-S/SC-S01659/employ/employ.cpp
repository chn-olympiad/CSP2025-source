#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
template <typename T> void getmin(T &a,T b){
	if(b<a) a=b;
	return;
}
template <typename T> void getmax(T &a,T b){
	if(b>a) a=b;
	return;
}
const ll MOD=998244353;
template <typename T> void getadd(T &a,T b){
	a=(a+b)%MOD;
	return;
}
ll kmi(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
int n,m,k;
ll fac[505],inv[505];
string str;
int s[505],c[505];
int sum[505];
ll f[505][505];
ll C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;++i) fac[i]=fac[i-1]*i%MOD;
	for(int i=0;i<=500;++i) inv[i]=kmi(fac[i],MOD-2);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i){
		s[i]=str[i-1]-'0';
		k+=s[i];
		sum[i]=s[i]+sum[i-1];
	}
	for(int i=1;i<=n;++i){
		++c[read()];
	}
	for(int i=1;i<=n;++i){
		c[i]+=c[i-1];
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		if(s[i]==0){
			for(int j=0;j<=n;++j){
				if(j>=1) getadd(f[i][j],f[i-1][j-1]);
			}
		}
		else{
			for(int j=0;j<=n;++j){
				getadd(f[i][j],f[i-1][j]);
				if(j>=1&&c[j-1]-(j-1-(i-1-sum[i-1]))>=0){
					getadd(f[i][j],f[i-1][j-1]*(c[j-1]-(j-1-(i-1-sum[i-1])))%MOD);
//					if(f[i-1][j-1]) cout<<i-1<<" "<<j-1<<"->"<<i<<" "<<j<<":"<<c[j-1]-(j-1-(i-1-sum[i-1]))<<endl;
				}
			}
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
//			if(f[i][j]) cout<<i<<" "<<j<<":"<<f[i][j]<<endl;
		}
	}
	ll ans=0;
	for(int i=n-m+1;i<=n;++i){
		ll sum=0;
		if((n-(i-(n-k)))>=0) sum=f[n][i]*fac[n-(i-(n-k))]%MOD;
		sum=sum*C(m-1,(i-(n-m+1)));
		getadd(ans,(i-(n-m+1))%2==0?sum:MOD-sum);
//		cout<<i<<":"<<f[n][i]<<" "<<n-(i-(n-k))<<" "<<fac[n-(i-(n-k))]<<" "<<(i-(n-m+1))<<":"<<sum<<endl;
	}
	ans=(fac[n]-ans+MOD)%MOD;
	cout<<ans<<endl;
	
	return 0;
}
/*


constellation
 
*/