#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=510;
const int mod=998244353;
struct modint{
	int val;
	inline int Mod(int x){return (x)>=mod?(x)-mod:(x);}
	inline int norm(int x){return (x)<0?(x+mod):(x);}
	modint(){val=0;}
	modint(int x):val(Mod(norm(x))){;}
	modint(ll x):val(norm(x%mod)){;}
	modint& operator +=(modint x){val=Mod(val+x.val);return *this;}
	modint& operator -=(modint x){val=norm(val-x.val);return *this;}
	modint& operator *=(modint x){val=(1ll*val*x.val)%mod;return *this;}
	modint operator +(modint x)const{return modint(*this)+=x;}
	modint operator -(modint x)const{return modint(*this)-=x;}
	modint operator *(modint x)const{return modint(*this)*=x;}
	friend ostream& operator <<(ostream &o,modint x){return o<<x.val;}
}frac[N],inv[N],f[N][N],g[N][N];
int p[N],n,m,c[N],s[N],ans,sum[N],cnt[N];

inline modint expow(modint x,int y){
	modint res=1;for(;y;y>>=1,x*=x) if(y&1) res*=x;return res;
}
inline void init(int n=500){
	frac[0]=inv[0]=1;for(int i=1;i<=n;++i) frac[i]=frac[i-1]*i;
	inv[n]=expow(frac[n],mod-2);for(int i=n-1;i;--i) inv[i]=inv[i+1]*(i+1);
}
inline modint C(int n,int m){return n<m||m<0?0:frac[n]*inv[m]*inv[n-m];}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;++i){p[i]=i;char x;cin>>x;s[i]=x-'0';}
	for(int i=1;i<=n;++i) cin>>c[i];
	if(n<=10){
		do{
			int now=0;
			for(int i=1;i<=n;++i) if(now>=c[p[i]]||!s[i]) ++now;
			ans+=(n-now>=m);
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<'\n';
	}else if(m==1){
		init();
		for(int i=1;i<=n;++i) if(s[i]) ++sum[i-1];
		for(int i=1;i<=n;++i) ++cnt[c[i]];
		for(int i=1;i<=n;++i) cnt[i]+=cnt[i-1];
		modint ans=C(cnt[0],sum[0]);
		for(int i=1;i<=n;++i){
			ans*=C(cnt[i]-sum[i-1],sum[i]);
			sum[i]+=sum[i-1];
		}
		cout<<frac[n]-ans*frac[n-sum[n]]<<'\n';
	}else {
		init();
		f[0][0]=1;
		for(int i=1;i<=n;++i) ++sum[c[i]],++cnt[c[i]];
		for(int i=1;i<=n;++i) sum[i]+=sum[i-1];
		for(int i=0;i<n;++i){
			for(int j=0;j<=n;++j) for(int k=0;k<=n;++k) g[j][k]=f[j][k],f[j][k]=0;
			int op=s[i+1];
			if(op==1){
				//填合法的数 
				for(int j=0;j<=n;++j){
					for(int k=0;k<=n;++k){
						if(!g[j][k].val) continue;
						f[j][k+1]+=g[j][k];
					}
				}
				//填不合法的数 
				for(int j=0;j<=n;++j){
					for(int k=0;k<=n;++k){
						if(!g[j][k].val) continue;
						for(int z=0;z<=min(k,cnt[j+1]);++z){
							modint xs=C(k,z);
//							cout<<"--- "<<i<<' '<<j<<' '<<k<<' '<<z<<' '<<xs<<' '<<C(sum[j]-i+k,1)<<' '<<g[j][k]<<'\n';
							f[j+1][k-z]+=g[j][k]*xs*C(sum[j]-i+k,1);
						}
					}
				}
			}else {
				//填不合法的数 
				for(int j=0;j<=n;++j){
					for(int k=0;k<=n;++k){
						if(!g[j][k].val) continue;
						for(int z=0;z<=min(k,cnt[j+1]);++z){
							modint xs=C(k,z);
//							cout<<"--- "<<i<<' '<<j<<' '<<k<<' '<<z<<' '<<xs<<' '<<C(sum[j]-i+k,1)<<' '<<g[j][k]<<'\n';
							f[j+1][k-z]+=g[j][k]*xs*C(sum[j]-i+k,1);
							f[j+1][k-z+1]+=g[j][k]*xs;
						}
					}
				}				
			}
//			cout<<"-------------\n";
//			for(int j=0;j<=n;++j){
//				for(int k=0;k<=n;++k) cout<<f[j][k]<<' ';
//				cout<<'\n';
//			}
		}
		modint ans=0;
		for(int i=0;i<=n-m;++i) ans+=f[i][sum[n]-sum[i]]*frac[sum[n]-sum[i]];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
	哦哦我悟了。
	考虑 m=1 的部分分，发现不合法当且仅当对于每个 s_i=1 都有 c_i<i。
	拓展一下去： 假设之前已经拒绝了 j 个人，那么第 i 个人合法当且仅当 c_i>j。 
	考虑从小到大插入 c。 
	我好像会了，f_{i,j,k} 表示考虑了前 i 天，有 j 个人没被录取，已经填了 k 个 >j 的数。 
	然后 s_i=0 就相当于…… 
	先实现 O(n^4) 的。 
*/