#include <bits/stdc++.h>
using namespace std;
const int N=1e5+3;
typedef long long ll;
int t,n,a[N][5],ans;
void dfs(int pos,int l1,int l2,int l3,int sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return;
	}
	if(l1)dfs(pos+1,l1-1,l2,l3,sum+a[pos][1]);
	if(l2)dfs(pos+1,l1,l2-1,l3,sum+a[pos][2]);
	if(l3)dfs(pos+1,l1,l2,l3-1,sum+a[pos][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,n>>1,n>>1,n>>1,0);
		cout<<ans<<'\n';
	}
	return 0;
}

