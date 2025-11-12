#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,ans,dp[2][110][110][110],a1,a2,a3,b[100010];
struct node{
	int x,y,z;
}a[1000010];
bool cmp(node q,node h){
	return q.x>h.x;
}
void dfs(int t,int a1,int a2,int a3,int sum){
	if(sum+b[t]<=ans){
		return ;
	}
	if(t>n){
		ans=max(ans,sum);
		return ;
	}
	if(a1<n/2&&a[t].x!=0)dfs(t+1,a1+1,a2,a3,sum+a[t].x);
	if(a2<n/2&&a[t].y!=0)dfs(t+1,a1,a2+1,a3,sum+a[t].y);
	if(a3<n/2&&a[t].z!=0)dfs(t+1,a1,a2,a3+1,sum+a[t].z);
	dfs(t+1,a1,a2,a3,sum);
}
bool cmp2(node q,node h){
	return q.x>h.x||q.x==h.x&&q.y>h.y||q.x==h.x&&q.y==h.y&&q.z>h.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+1+n,cmp);
		if(n<=200){
			ans=0;
			memset(dp,0,sizeof(dp));
			dp[0][0][0][0]=0;
			for(i=1;i<=n;i++){
				int now=i%2;
				for(a1=0;a1<=min(i,n/2);a1++)	
					for(a2=0;a2<=min(i-a1,n/2);a2++){
						a3=i-a1-a2;
						if(a3<=n/2&&a3>=0){
							if(a1+1<=n/2)dp[now^1][a1+1][a2][a3]=max(dp[now^1][a1+1][a2][a3],(dp[now][a1][a2][a3]+a[i].x));
							if(a2+1<=n/2)dp[now^1][a1][a2+1][a3]=max(dp[now^1][a1][a2+1][a3],(dp[now][a1][a2][a3]+a[i].y));
							if(a3+1<=n/2)dp[now^1][a1][a2][a3+1]=max(dp[now^1][a1][a2][a3+1],(dp[now][a1][a2][a3]+a[i].z));
							ans=max(ans,dp[now^1][a1+1][a2][a3]);
							ans=max(ans,dp[now^1][a1][a2+1][a3]);
							ans=max(ans,dp[now^1][a1][a2][a3+1]);
						}
					}
			}
			cout<<ans<<'\n';
		}
		else{
			int fl=ans=0;
			for(int i=1;i<=n;i++)
				if(a[i].y!=0||a[i].z!=0)fl=1;
			if(fl==0){
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n/2;i++)ans+=a[i].x;
				cout<<ans<<'\n';
			}
			else{
				b[n+1]=0;
				sort(a+1,a+1+n,cmp2);
				for(i=n;i>=1;i--)
					b[i]=b[i+1]+max(a[i].x,max(a[i].y,a[i].z));
				dfs(1,0,0,0,0);
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
/*
60pts
*/
