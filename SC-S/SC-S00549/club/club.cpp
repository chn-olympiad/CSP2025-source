#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
typedef long long ll;
struct node{
	ll n,a[N][4],b[N];
	void solve(){
		scanf("%lld",&n);
		up(i,1,n) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		ll ans=0,k1=0,k2=0,k3=0;
		up(i,1,n){
			ll p=max(max(a[i][1],a[i][2]),a[i][3]);ans+=p;
			if(a[i][1]==p) k1++;
			else if(a[i][2]==p) k2++;
			else k3++;
		}
		if(k1<=n/2&&k2<=n/2&&k3<=n/2){printf("%lld\n",ans);return;}
		if(k1>n/2){ll cnt=0;
			up(i,1,n){
				ll p=max(max(a[i][1],a[i][2]),a[i][3]);
				if(a[i][1]==p){
					b[++cnt]=a[i][1]-max(a[i][2],a[i][3]);
				}
			}
			sort(b+1,b+cnt+1);up(i,1,cnt-(n/2)) ans-=b[i];
			printf("%lld\n",ans);
		}
		else if(k2>n/2){ll cnt=0;
			up(i,1,n){
				ll p=max(max(a[i][1],a[i][2]),a[i][3]);
				if(a[i][2]==p){
					b[++cnt]=a[i][2]-max(a[i][1],a[i][3]);
				}
			}
			sort(b+1,b+cnt+1);up(i,1,cnt-(n/2)) ans-=b[i];
			printf("%lld\n",ans);
		}
		else{ll cnt=0;
			up(i,1,n){
				ll p=max(max(a[i][1],a[i][2]),a[i][3]);
				if(a[i][3]==p){
					b[++cnt]=a[i][3]-max(a[i][1],a[i][2]);
				}
			}
			sort(b+1,b+cnt+1);up(i,1,cnt-(n/2)) ans-=b[i];
			printf("%lld\n",ans);
		}
	}
}p[7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) p[T].solve();return 0;
} 