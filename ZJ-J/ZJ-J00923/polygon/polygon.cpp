#include<bits/stdc++.h>
using namespace std;
long long k,n,a[5005],ans=0,t[5005];
void dfs(int x,int f,int m){
	if(x>n)return;
	if(f>k&&f!=m)ans++;
	ans%=998244353;
	m=f;
	dfs(x+1,f+a[x+1],m);
	dfs(x+1,f,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],t[a[i]]++;
	if(t[1]==n&&n>20){
		long long sum=1;
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=1;j<=i;j++){
				sum*=(n-j+1);
				sum/=j;
				sum%=998244353;
			}
			ans+=sum;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=n;i++){
			k=a[i];
			dfs(i,0,0);
		}
		cout<<ans%998244353;
	}
	return 0;
}
