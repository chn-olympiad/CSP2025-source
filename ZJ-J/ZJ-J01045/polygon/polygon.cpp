#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans,n,a[5010];
ll sum1;
void dfs(int x,int cnt,int len,int sum,int mx){
	if(cnt==len){
		if(mx*2<sum){
			ans++;
			ans%=998244353;
		}
		return;
	}
	if(n-x<len-cnt){
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,cnt+1,len,sum+a[i],max(mx,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int len=3;len<=n;len++){
			for(int i=1;i<=n;i++){
				dfs(i,1,len,a[i],a[i]);
			}
		}
	}else{
		for(int len=3;len<=n;len++){
			sum1=1;
			for(int i=0;i<len;i++){
				sum1*=(n-i);
				sum1/=(len-i);
				sum1%=998244353;
			}
			ans+=sum1;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}