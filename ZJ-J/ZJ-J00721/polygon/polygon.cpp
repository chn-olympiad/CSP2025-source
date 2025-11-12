#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool mp[5005];
void dfs(int step,int sum,int ma,int cnt){
	if(step==n+1){
		if(sum>ma*2){
			ans=(ans+1)%998244353;
		}
		return;
	}
	mp[step]=1;
	dfs(step+1,sum+a[step],a[step],cnt+1);
	if(n-step==2-cnt) return;
	mp[step]=0;
	dfs(step+1,sum,ma,cnt);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
//made by S_A_T_E_L_L_I_T_E(luogu_737070)
//maybe 40
//I love phigros
