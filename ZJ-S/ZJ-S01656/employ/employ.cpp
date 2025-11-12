#include<bits/stdc++.h>
using namespace std;
const long long N=5e2+5,mod=998244353;
long long n,m,c[N],b[N],f[N],ans,g[N],fac[N],inv[N],d[N];
string s,sng;
inline bool check(){
	long long s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') s2++;
		else{
			if(s2<c[b[i]]) s1++;
			else s2++;
		}
	}
	return s1>=m;
}
inline long long ksm(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1){
			res=res*x%mod;
			y--;
		}
		else{
			y/=2;
			x=x*x%mod;
		}
	}
	return res%mod;
}
inline void dfs1(long long x){
	if(x>n){
		ans+=check();
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			b[x]=i;
			dfs1(x+1);
			f[i]=0;
		}
	}
}
inline long long P(long long n){
	return fac[n]%mod;
}
inline void solve1(){
	dfs1(1);
	cout<<ans%mod<<'\n';
	return ;
}
inline void solve(){
	cin>>n>>m;
	s=" ";
	cin>>sng;
	s+=sng;
	for(int i=1;i<=n;i++) cin>>c[i];
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2)%mod;
	for(int i=n-1;i>0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	sort(c+1,c+n+1);
	if(n<=10){
		//1-2
		solve1();
		return ;
	}
	if(m==1){
		ans=0;
		//12~14
		for(int i=1;i<=n;i++) d[c[i]]++,g[i]=1;
		long long s1=0;
		for(int i=0;i<=n;i++) s1+=d[i],f[i]=s1;
		long long s2=0,s3=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				s2++;
				continue;
			}
			for(int j=1;j<=n;j++){
				if(c[j]>=i){
					ans+=g[j]*P(n-i+s2)%mod;
				}
	//			cout<<ans<<" "<<s2<<'\n';
				ans%=mod;
				g[j]*=max(0ll,f[i-1]-(c[j]<i)-s3);
				g[j]%=mod;
	//			cout<<i<<" "
			}
			s3++;
		}
		cout<<ans<<'\n';
		return ;
	}
	if(m==n){
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				cout<<0<<'\n';
				return ;
			}
		}
		cout<<fac[n]%mod<<'\n';
		return ;
	}
	cout<<0<<'\n';
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

