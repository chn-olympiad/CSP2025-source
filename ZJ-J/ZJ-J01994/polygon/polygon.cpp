#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x0 XA_0
#define y0 YA_0
#define x1 XA_1
#define y1 YA_1
int n,ans;
const int N=5005,MOD=998244353;
int a[N],f[N];
int get_max(int l,int r){
	int ans=-1;
	for(int i=l;i<=r;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}
void dfs(int x,int cnt,int maxx){
	if(x>n){
		if(cnt>2*maxx)ans++;
		return;
	}else{
		dfs(x+1,cnt,maxx);
		if(a[x]>maxx){
			dfs(x+1,cnt+a[x],a[x]);
		}else{
			dfs(x+1,cnt+a[x],maxx);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%MOD;
	return 0;
}

