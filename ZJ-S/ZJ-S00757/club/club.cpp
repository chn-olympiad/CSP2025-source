#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3],ans;
int maxn[N],summ[N];
void dfs(int now,int sum,int cnt0,int cnt1,int cnt2){
	if(sum+summ[now]<=ans)
		return;
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt0<n/2)
		dfs(now+1,sum+a[now][0],cnt0+1,cnt1,cnt2);
	if(cnt1<n/2)
		dfs(now+1,sum+a[now][1],cnt0,cnt1+1,cnt2);
	if(cnt2<n/2)
		dfs(now+1,sum+a[now][2],cnt0,cnt1,cnt2+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			maxn[i]=max(a[i][0],max(a[i][1],a[i][2]));
		}
		summ[n+1]=0;
		for(int i=n;i>=1;i--)
			summ[i]=summ[i+1]+maxn[i];
		ans=0;
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
