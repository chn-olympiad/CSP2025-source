#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,flag,b[5005];
void dfs(int k,int sum,int maxn,int cnt){
	if(k>n){
		if(sum>2*maxn&&cnt>=3)ans++;
		ans%=998244353;
		return;
	}
	dfs(k+1,sum+a[k],a[k],cnt+1);
	dfs(k+1,sum,maxn,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2;
			ans%=998244353;
		}
		ans=ans-n-1-(n-1)*n/2;
		ans%=998244353;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
