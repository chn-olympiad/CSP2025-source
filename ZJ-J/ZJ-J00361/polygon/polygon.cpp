#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],cnt;
const ll mod=998244353;
void dfs(int i,int sum,int ma,int use){
	if(i==n+1){
		if(use<3){
			return;
		}
		if(sum>ma*2){
			cnt++;
		}
		return;
	}
	dfs(i+1,sum+a[i],max(ma,a[i]),use+1);
	dfs(i+1,sum,ma,use);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool all1=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			all1=0;
		}
	}
	if(all1){
		ll ans=0;
		for(int i=3;i<=n;i++){
			//C(n,i)
			ll tmp=1;
			for(int j=i+1;j<=n;j++){
				tmp*=i;
				tmp%=mod;
			}
			ans+=tmp;
			ans%=mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}