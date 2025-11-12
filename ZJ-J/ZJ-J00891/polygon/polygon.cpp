#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=998244353;
int n,a[N],ans,cnt;
void dfs(int k,int x,int mx,int sum,int flag){
	if(x>n){
		if(flag){
			if(sum>mx*2){
				ans++;
			}
			ans%=M;
		}
		return;	
	} 
	if(k>=3){
		if(sum>mx*2&&flag){
			ans++;
		}
		ans%=M;
	}
	dfs(k+1,x+1,max(mx,a[x]),sum+a[x],1);
	dfs(k,x+1,mx,sum,0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;                      
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,1,0,0,1);
	cout<<ans<<'\n';
	return 0;
}