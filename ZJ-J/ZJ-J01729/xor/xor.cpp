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
const ll N=1e6+10;
ll n,k,a[N],t[N],f[N],s,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t[s]=i,s^=a[i],f[i]=f[i-1];
		if(t[s^k]!=0){
			f[i]=max(f[i],f[t[s^k]-1]+1);
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
