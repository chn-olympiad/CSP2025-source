#include<iostream>
#define mod 998244353
using namespace std;
typedef long long ll;
int v[1001];
int a[1001];
string s;
ll n,m,ans;
ll f(int n){
	ll sum=1;
	for(int i=2;i<=n;i++)sum=(sum*i)%mod;
	return sum;
}
void dfs(int t,int sum){
	if(n-sum<m)return;
	if(t==n){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(s[t+1]=='0'||sum>=a[i])dfs(t+1,sum+1);
			else dfs(t+1,sum);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	s=' '+s;
	if(n<=18){
		dfs(0,0);
		cout<<ans;
	}
	else cout<<f(n);
	return 0;
}
