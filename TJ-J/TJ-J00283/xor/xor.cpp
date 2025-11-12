#include<bits/stdc++.h>
using namespace std;
int cnt1,cnt0,n,k,res,cnt;
int a[500005]={};
void solve1(){
	if(k==1)cout<<cnt1;
	else cout<<cnt1/2+cnt0;
	return;
}
void dfs(long long ans,long long dq){
	//cout<<ans<<' '<<dq<<' '<<cnt<<endl;
	if(dq>=n+1){
		if(ans==k)cnt++;
		//if(dq>n)cnt--;
		//cout<<'#'<<" "<<maxx<<' '<<sum<<endl;;
		res=max(res,cnt);
		return;
	}
	if(ans==k){//ans^a[i]
		cnt++;
		dfs(a[dq],dq+1);
		cnt--;
	}else{
		dfs(ans^a[dq],dq+1);
		dfs(a[dq],dq+1);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		else if(a[i]==0)cnt0++;
	}
	if(cnt1+cnt0==n){
		solve1();
	}else{
		dfs(0,1);
		cout<<res;
	}
	return 0;
}
