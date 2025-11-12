#include<bits/stdc++.h>
using namespace std;
int a[5001];
bool used[5001];
const long long _mod=998244353;
long long ans=0; 
void dfs(int end,int n,int c,int _max,int lest,long long sum){
	if(c>n){
		if(sum>_max*2) ans++,ans%=_mod;
		return;
	}
	for(int i=lest+1;i<=end;i++){
		if(!used[i]){
			used[i]=1;
			dfs(end,n,c+1,max(_max,a[i]),i,sum+a[i]);
			used[i]=0;
		}
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(a[n]==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			for(int j=n-i+1;j>0;j--)sum+=j,sum%=_mod; 
		}
		cout<<sum%_mod;
		return 0;
	}
	if(n<30){
		for(int i=3;i<=n;i++){
			dfs(n,i,1,-1,0,0);
		}
		cout<<ans;
		return 0;
	}
	long long sum=0;
	for(int i=3;i<=n;i++){
		for(int j=n-i+1;j>0;j--)sum+=j,sum%=_mod; 
	}
	cout<<sum%_mod;
	return 0;
}
