#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;

int n,k,ans;
int a[N],sum[N];

void dfs(int x,int cnt){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	bool flag=0;
	for(int i=x;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp=sum[j]^sum[i-1];
			if(tmp==k){
				dfs(j+1,cnt+1);
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int ccc1=0,ccc0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ++ccc1;
		if(a[i]==0) ++ccc0;
		sum[i]=sum[i-1]^a[i];
	}
	if(ccc1==n&&k==0){
		cout<<n/2;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
