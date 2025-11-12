#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5000005;
long long n,k,lst=0,mx,a[MAXN],p[MAXN],f[1<<23],ans;
void solve(){
	memset(f,-1,sizeof(f));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	mx=max(mx,255ll);
	f[0]=n+1;
	for(int i=1;i<=n;i++){
		if(f[p[i]^p[lst]^k]>lst||a[i]==k){
			ans++;
			lst=i;
		}else if(p[i]^p[lst]){
			f[p[i]^p[lst]]=i;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}