#include<bits/stdc++.h>
#define int long long  
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],vis[N],ans;
void dfs(int sum,int m,int n,int k,int ct){
	if(m==n+1){
		if(sum<=k) return ;
		if(ct<2) return ;
		ans++;
//		cout<<sum<<" "<<m<<" "<<n<<" "<<k<<" "<<ct<<" "<<ans<<endl;
		return;
	}	
	dfs(sum+a[m],m+1,n,k,ct+1);	
	dfs(sum,m+1,n,k,ct);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n>=500){
		int sum=0;
		for(int i=3;i<=n;i++){
			int j=n,id=i,x=1,y=1;
			while(id--){
				x=x*j%mod;
				y=y*(id+1)%mod;
				j--;
			}
			sum+=x/y;
			sum%=mod;
		}
		cout<<sum<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++){
		int k=a[i];
		dfs(0,1,i-1,k,0);
	}
	cout<<ans%mod<<endl;
}
/*
5
1 2 3 4 5
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
1042392

*/
