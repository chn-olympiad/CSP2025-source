/*
部分分：s[i]=1
直接输出全排列种数取余998244353 (乘一次取余一次)
*/
#include <bits/stdc++.h>
using namespace std;
int m,ans,per;
long long n;
string s;
int dfs(long long n){
	long long ans=1;
	while(n>0){
		ans*=n;
		ans%=998244353;
		n--; 
	}
	return ans; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++){
		if(s[i]=='0'){
			cout<<0;
			return 0;
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>per;
		if(per==0){
			m++;
		}
		if(m>n){
			cout<<0;
			return 0;
		}
	}
	cout<<dfs(n);
	return 0;
}
