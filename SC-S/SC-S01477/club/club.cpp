#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010][4];
int n;
int ans=0;
void dfs(int n1,int n2,int n3,int i,int ncnm){
	if(i>n){
		ans=max(ans,ncnm);
		return;
	}
	if(n1<n/2)dfs(n1+1,n2,n3,i+1,ncnm+a[i][1]);
	if(n2<n/2)dfs(n1,n2+1,n3,i+1,ncnm+a[i][2]);
	if(n3<n/2)dfs(n1,n2,n3+1,i+1,ncnm+a[i][3]);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(0,0,0,1,0);
		cout << ans << '\n';
	}
	return 0;
}