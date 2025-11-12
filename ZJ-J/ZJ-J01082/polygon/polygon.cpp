#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
void dfs(int x,int mx,int sum,int cnt){
	if(cnt>=3 && sum>mx*2){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,max(mx,a[i]),sum+a[i],cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans;
}