#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5001],t[5001];
int maxx;
int ans;
void dfs(int sum,int maxx,int cnt,int last){
	if(last>n){
		if(sum>2*maxx && cnt>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(sum+a[last],max(maxx,a[last]),cnt+1,last+1);
	dfs(sum,maxx,cnt,last+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(flag==true){
		long long sum=0;
		for(int i=3;i<=n;i++){
			long long sum2=1;
			for(int j=1;j<=min(i,n-i);j++){
				sum2*=(n-j+1);
				sum2/=j;
				sum2%=mod;	
			}
			sum=(sum2+sum)%mod;
		}
		cout<<sum;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
