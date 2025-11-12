#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,ans;
int a[100005][5],cnt[5],b[100005];//dp[i][w1][w2][w3]
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(sum,ans);
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(k+1,sum+a[k][i]);
			cnt[i]--;
		}
	}
}
void dfs2(int k,int sum){
	if(k==n+1){
		ans=max(sum,ans);
	}
	for(int i=1;i<=2;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(k+1,sum+a[k][i]);
			cnt[i]--;
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		int flag2=0,flag3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)flag2=1;
			if(a[i][3]!=0)flag3=1;
		}
		if(flag2==0&&flag3==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
//				cout<<b[i]<<" ";
			}
			cout<<ans<<endl;
		}else if(flag3==0){
			dfs2(1,0);
			cout<<ans<<endl;
		}else{
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}