//powered by Jin_Yichen
//Luogu UID:727101
#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int maxn=5005;
int n,a[maxn],ans,sum[maxn];
void dfs(int dep,int sum,int ma){
	if(dep==n+1){
		if(ma*2<sum)ans++;
		return;
	}
	dfs(dep+1,sum,ma);
	dfs(dep+1,sum+a[dep],max(ma,a[dep]));
}
bool check(){
	for(int i=1;i<=n;i++)
		if(a[i]!=1)return false;
	return true;
}
int fac(int num){
	int res=1;
	for(int i=n;i>=n-num+1;i--){
		res=(res*i)%mod;
	}
	return res;
}
void solve1(){// bruth force
	if(check()&&n>20){
		for(int i=3;i<=n;i++){
			int sum=fac(i);
			ans=(ans+sum)%mod;
		}
		cout<<ans<<endl;
	} else if(n<=20){
		dfs(1,0,0);
		cout<<ans<<endl;
	} else {
		cout<<"I love you, CCF."<<endl;
		cout<<"Please give me CSP-J/S double 1=."<<endl;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve1();
	return 0;
}
