#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define put(a) printf("%lld\n",a)
#define scan(a,b) scanf("%lld%lld",&a,&b)
int n,m,k,t,ans,cnt;
int T;
const int inf=1e17;
const int N=5e5+10;
int cntt[N];
int a[N][4],b[4][N];
void solve(){
	ans=0;
	sc(n);
	cntt[1]=cntt[2]=cntt[3]=0;
	rep(i,1,n){
		int mx=-inf;
		sc(a[i][1]);
		scan(a[i][2],a[i][3]);
		rep(j,1,3){
			mx=max(mx,a[i][j]);
		}
		rep(j,1,3){
			if(mx==a[i][j]){
				ans+=a[i][j];
				k=j;
				break;
			}
		}
		int mn=inf;
		rep(j,1,3){
			if(j==k){
				continue;
			}
			mn=min(mn,mx-a[i][j]);
		}
		b[k][++cntt[k]]=mn;
		
	}
	rep(j,1,3){
		if(cntt[j]>n/2){
			sort(b[j]+1,b[j]+1+cntt[j]);
			rep(i,1,cntt[j]-n/2){
				ans-=b[j][i];
			}
			break;
		}
	}
	
	
	put(ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=1;
	sc(T);
	while(T--){
		solve();
	}

	
	
	return 0;
}
