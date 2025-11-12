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
	const int N=100005;
	int n,a[N][3],b[N],c[3];
	int tmp[N],len;
	void MAIN1(){
		cin>>n;
		For(i,1,n) For(j,0,2) cin>>a[i][j];
		int ans=0;
		For(i,1,n){
			int mx=max({a[i][0],a[i][1],a[i][2]});
			ans+=mx;
			For(j,0,2) if(a[i][j]==mx){
				b[i]=j;
				break;
			}
		}
		For(i,1,n) c[b[i]]++;
		For(j,0,2){
			if(c[j]>n/2){
				len=0;
				For(i,1,n) if(b[i]==j){
					int mx=-inf;
					For(k,0,2) if(k!=j) MAX(mx,a[i][k]);
					tmp[++len]=-a[i][j]+mx;
				}
				sort(tmp+1,tmp+len+1,greater<int>());
				For(i,1,c[j]-n/2) ans+=tmp[i];
				break;
			}
		}
		cout<<ans<<"\n";
	}
	void _MAIN1(){
		For(j,0,2) c[j]=0;
	}
	int T;
	void MAIN(){
		cin>>T;
		For(_,1,T) MAIN1(),_MAIN1();
	}
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}