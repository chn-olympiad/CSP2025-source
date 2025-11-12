#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,res[5010];
const int M=998244353;
void dfs(int step,int now,int k){
	if(step>n&&now!=k)
		return;
	if(now==k){
		int sum=0,mx=0;
		for(int i=1;i<=now;++i){
			mx=max(mx,res[i]);
			sum+=res[i];
		}
		if(mx*2<sum)
			++ans;
		return;
	}
	res[now+1]=a[step];
	dfs(step+1,now+1,k);
	res[now+1]=0;
	dfs(step+1,now,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]=a[i]%M;
	}
	for(int i=3;i<=n;++i){
		dfs(1,0,i);
	}
	cout<<ans%M;
	return 0;
}

