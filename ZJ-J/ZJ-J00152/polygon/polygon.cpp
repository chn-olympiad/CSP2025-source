#include<bits/stdc++.h>
using namespace std;
int n,a[1005],ans=0;
void dfs(int mgs,int maxn,int nowmg,int total){
	if(mgs>=3&&total>maxn*2){
		ans++;
		ans%=998244353;
	}
	for(int i=nowmg+1;i<=n;i++){
		dfs(mgs+1,max(maxn,a[i]),i,total+a[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=n;i>=3;i--){
			int m;
			if(i>n/2) m=n-i;
			else m=i;
			long long num=1;
			for(int j=n;j>=n-m+1;j--){
				num*=j;
				num%=998244353;
			}
			for(int j=m;j>=1;j--) num/=j;
			ans+=num;
			ans%=998244353;
		}
		cout<<ans%998244353;
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(1,a[i],i,a[i]);
		}
		cout<<ans%998244353;
	}
	return 0;
}
