#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int n,a[N];
int ans=0;
int k;
void dfs(int pos,int sum,int ma,int cnt){
	if(cnt==k){
		if(sum>2*ma) ans++;
		return ;
	}
	if(pos>n) return ;
	dfs(pos+1,sum+a[pos],max(ma,a[pos]),cnt+1);
	dfs(pos+1,sum,ma,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(k=3;k<=n;k++) dfs(1,0,-1,0);
	cout<<ans;

	return 0;
}
