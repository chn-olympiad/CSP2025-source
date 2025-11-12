#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
//long long dp[5010][5010];
int n;
int a[5010];
long long ans=0;
long long C(int n,int x){
	int k=1;
	for(int i=n-x+1;i<=n;i++)k*=i;
	for(int i=1;i<=x;i++)k/=i;
	return k;
}
void dfs(int i,int cnt,int maxi){
	if(i>n){
		long long p=lower_bound(a+1,a+n+1,cnt)-a-1;
		if(p<maxi)return ;
		cout<<p<<' '<<maxi<<'\n';
		ans=(ans+p-maxi)%M;
		
		return ;
	}
	dfs(i+1,cnt,maxi);
	dfs(i+1,cnt+a[i],i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	if(cnt==n){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%M;
		}
		cout<<ans%M;
		return 0;		
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
