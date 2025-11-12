#include<bits/stdc++.h>
using namespace std;
string s;
int a[5005],cnt=0,n,m,ans1,flag=1;
long long MOD=998244353;
void dfs(int x,int p,int ans,int k){
	if(p==k){
		if(ans>x) cnt++;
		return;
	}
	dfs(x,p+1,ans+a[p],k);
	dfs(x,p+1,ans,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		long long ans=0,s[5005];
		s[1]=1;
		s[0]=1;
		for(long long i=2;i<=n;i++){
			s[i]=s[i-1]*i%MOD;
		}
		for(int i=3;i<=n;i++){
			ans=(ans+s[n]/(s[n-i]*s[i]))%MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(a[i],1,0,i);
	}
	cout<<cnt;
	return 0;
} 
