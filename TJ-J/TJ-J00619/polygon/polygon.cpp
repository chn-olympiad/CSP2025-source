#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5001],n,ans;
void dfs(int pos,int num,int maxn,int sum){
	if(pos>n){
		if(num>=3&&sum>maxn*2)ans=(ans+1)%998244353;
		return;
	}
	dfs(pos+1,num+1,max(maxn,a[pos]),sum+a[pos]);
	dfs(pos+1,num,maxn,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=1;
			break;
		}
	}
	if(f){
		dfs(1,0,0,0);
		cout<<ans;
	}else{
		for(int t=3;t<=n;t++){
			for(int i=t;i<=n;i++){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
