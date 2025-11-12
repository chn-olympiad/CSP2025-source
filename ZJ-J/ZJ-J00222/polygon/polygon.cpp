#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int dfs(int sum,int last){
	int ans=0;
	if(sum<0) ans++;
	for(int i=last-1;i>=1;i--){
		ans+=dfs(sum-a[i],i)%998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=3;i<=n;i++) ans+=dfs(a[i],i);
	cout<<ans;                                    
	return 0;
}