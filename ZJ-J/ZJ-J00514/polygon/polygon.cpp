#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int a[N],n,res=0;
void dfs(int x,int num,int sum){//how many bian
	if(x>n) return ;
	if(num>=2 and sum>a[x]) res=(res+1)%mod;
	dfs(x+1,num+1,sum+a[x]);
	dfs(x+1,num,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3){
		if(n<=2) cout<<0;
		else{
			if(a[1]+a[2]>a[3]) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if(a[1]==a[n]){
		ll cnt=1,sum=1;
		for(int i=1;i<=n-3;i++){
			cnt=(1LL*cnt*(n-i+1)/i)%(ll)mod;
			sum=(sum+cnt)%(ll)mod;
		}
		cout<<sum;
		return 0;
	}
	dfs(1,0,0);
	cout<<res;
	return 0;
}