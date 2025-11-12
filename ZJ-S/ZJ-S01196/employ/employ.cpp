#include<bits/stdc++.h>
#define mod 998244353 
using namespace std;
long long n,m,ans,sum,a[505];
long long slt;
string s;
bool vis[505];
void dfs(int id,int sum){
	if(n-sum<m) return;
	if(id>n){
		if(n-sum>=m) slt++;
		slt%=mod;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(id+1,sum+(s[id-1]=='0')+(s[id-1]=='1' && a[i]<=sum));
			vis[i]=0;
		}
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') flag=false;
	}
	if(flag || m==1){//全是1  特殊性质A  6，8，16，17
		sum=1;
		for(long long i=1;i<=n;i++){
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
	}else{
		dfs(1,0);
		cout<<slt;
	}
	return 0;
}
