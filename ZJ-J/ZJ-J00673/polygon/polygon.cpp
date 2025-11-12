#include<bits/stdc++.h>
using namespace std;
const int N=5e3+17;
const int M=5e3+17;
const long long mod=998244353;
int n,k,maxn;
long long a[N],ans;
void dfs(int x,int s,int now,int maxn,long long sum){
	if(now==s){
		if(sum>maxn*2)ans++;
		return ;
	}
	if(x>n)return ;
	dfs(x+1,s,now,maxn,sum);
	dfs(x+1,s,now+1,a[x],sum+a[x]%mod);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		dfs(1,i,0,0,0);
	cout<<ans;
	return 0;
}