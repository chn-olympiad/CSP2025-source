#include<bits/stdc++.h>
using namespace std;
int n,a[4];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(&a[0],&a[n]);
	if(n==3){
		if(a[0]+a[1]>a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int ans=0,n,a[5000],sum=0,dp[5000][5000];
void dfs(int num_edge,int total_edge,int first_edge,int last_edge_num,int last_edge_long) {
	if(first_edge==n+1)return;
	if(total_edge==num_edge+1) {
		if(sum>2*last_edge_long) {
			ans++;
			ans%=998244353;
			if(first_edge+num_edge-1==n) {
				num_edge++;
				first_edge=0;
				total_edge=0;
				last_edge_num=0;
				last_edge_num=a[0];
			}
			return;
		}
	 else {
		if(first_edge+num_edge-1==n) {
			num_edge++;
			first_edge=0;
			total_edge=0;
			last_edge_num=0;
			last_edge_num=a[0];
		}
		return;
	}
	}
	for(int i=last_edge_num+1; i<n; i++) {
		sum+=a[i];
		dfs(num_edge,total_edge+1,first_edge,i,a[i]);
		sum-=a[i];
	}
	dfs(3,0,first_edge+1,-1,a[0]);
}
int main() {
	
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(&a[0],&a[n]);
	dfs(3,0,0,-1,a[0]);
	cout<<ans;
	return 0;
}*/