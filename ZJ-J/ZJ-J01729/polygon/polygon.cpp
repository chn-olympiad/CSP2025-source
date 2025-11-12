#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define lc (u<<1)
#define rc ((u<<1)|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pii;
const ll N=5000+10,p=998244353;
ll n,a[N],f[N],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++) ans=(ans+f[j])%p;
		for(int j=5001;j>=0;j--){
			ll z=j+a[i];
			if(z>5001) z=5001;
			f[z]=(f[z]+f[j])%p;
		}
	}
	cout<<ans;
	return 0;
}
