#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
string str;
int n,m,s[501],sum,c[501],answer,a[501];
bool flag[501];
long long power(int a){
	long long sum=1;
	for(int i=2;i<=a;i++){
		sum=(sum*i)%mod;
	}
	return sum;
}
void dfs(int x,int sum,int k){
	if(sum>=m){
		answer=(answer+power(n+1-x))%mod;
		return ;
	}
	if(x>n) return ;
	if(n-x+1+sum<m) return ;
	for(int i=1;i<=n;i++){
		if(flag[i]==false){
			flag[i]=true;
			if(s[x]==1&&k<c[i]) dfs(x+1,sum+1,k);
			else dfs(x+1,sum,k+1);
			flag[i]=false;
		}
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	str=" "+str;
	for(int i=1;i<=n;i++){
		s[i]=(str[i]^48);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<answer;
	return 0;
}
