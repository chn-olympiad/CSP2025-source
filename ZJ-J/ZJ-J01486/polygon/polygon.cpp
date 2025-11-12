#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,a[5055],stick[5055];
bool use[5055];
bool cmp(int x1,int x2){
	return x1>x2;
}
void dfs(int depth){
	if(depth>3){
		int maxn=INT_MIN,sum=0;
		for(int i=1;i<depth;i++){
			sum+=a[stick[i]];
			maxn=max(maxn,a[stick[i]]);
		}
		if(sum>2*maxn){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			stick[depth]=i;
			dfs(depth+1);
			use[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans%mod<<"\n";
	return 0;
}
