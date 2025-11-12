#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
namespace cjr2010{
	template<typename ta,typename tb>
	void MIN(ta &a,tb b){if(a>b) a=b;}
	template<typename ta,typename tb>
	void MAX(ta &a,tb b){if(a<b) a=b;}
	#define pop __builtin_popcount
	const int mod=998244353;
	void ADD(int& a,int b){if((a+=b)>=mod) a-=mod;}
	const int N=505;
	int n,m,b[N];
	char a[N];
	namespace SUB{
		int f[1<<18][19/*lu yong*/];
		void MAIN(){
			f[0][0]=1;
			For(s,0,(1<<n)-1){
				For(i,0,pop(s)){
					if(f[s][i]){
						if(a[pop(s)+1]=='0'){
							For(j,1,n){
								if(s&(1<<(j-1))) continue;
								ADD(f[s|(1<<(j-1))][i],f[s][i]);
							}
						}
						else{
							For(j,1,n){
								if(s&(1<<(j-1))) continue;
								if(pop(s)-i>=b[j]) ADD(f[s|(1<<(j-1))][i],f[s][i]);
								else ADD(f[s|(1<<(j-1))][i+1],f[s][i]);
							}
						}
					}
				}
			}
			int ans=0;
			For(i,m,n) ADD(ans,f[(1<<n)-1][i]);
			cout<<ans<<"\n";
		}
	}
	namespace SUB1{
		int fac[N],f[N];
		void MAIN(){
			fac[0]=1;For(i,1,n) fac[i]=fac[i-1]*i%mod;
			f[0]=1;int lst=0,c0=0;
			For(i,1,n){
				if(a[i]=='0'){c0++;continue;}
				int cnt=0;For(j,1,n) cnt+=(i-1>=b[j]);
				ADD(f[i],f[lst]*(cnt-(i-1-c0))%mod);
				lst=i;
			}
			cout<<(fac[n]-f[lst]*fac[c0]%mod+mod)%mod<<"\n";
		}
	}
	namespace SUB2{
		void MAIN(){
			For(i,1,n) if(!b[i]){cout<<"0\n";return ;}
			For(i,1,n) if(a[i]=='0'){cout<<"0\n";return ;}
			int facn=1;For(i,1,n) facn=facn*i%mod;
			cout<<facn<<"\n";
		}
	}
	void MAIN(){
		cin>>n>>m;
		cin>>(a+1);
		For(i,1,n) cin>>b[i];
		if(n<=18){SUB::MAIN();return ;}
		if(m==1){SUB1::MAIN();return ;}
		if(m==n){SUB2::MAIN();return ;}
		SUB::MAIN();
	}
}
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}