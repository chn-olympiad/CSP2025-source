#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,na,nb,nc,ia,ib,ic,vis[N],nn;
struct node {
	int val,id;
} a[N],b[N],c[N];
bool cmp(node x,node y) {
	return x.val>y.val;
}
void fa() {
	if (!vis[a[ia].id]&&na<nn/2)
		vis[a[ia].id]=1,ans+=a[ia].val,na++,n--;
	ia++;
}
void fb() {
	if (!vis[b[ib].id]&&nb<nn/2)
		vis[b[ib].id]=1,ans+=b[ib].val,nb++,n--;
	ib++;
}
void fc() {
	if (!vis[c[ic].id]&&nc<nn/2)
		vis[c[ic].id]=1,ans+=c[ic].val,nc++,n--;
	ic++;
}
int solve(int g,int h,int j) {
	int dp[N][3];
	for (int i=1; i<=n; i++) {
		if (dp[i-1][0])
			dp[i][0]=max(dp[i-1][1]+dp[i-1][2]-dp[i-1][0]-a[i].val,dp[i-1][0]+a[i].val);
		if (dp[i-1][1])
			dp[i][1]=max(dp[i-1][0]+dp[i-1][2]-dp[i-1][1]-b[i].val,dp[i-1][1]+b[i].val);
		if (dp[i-1][2])
			dp[i][2]=max(dp[i-1][0]+dp[i-1][1]-dp[i-1][2]-c[i].val,dp[i-1][2]+c[i].val);
	}
	return max(dp[n][1],max(dp[n][2],dp[n][0]));
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		na=nb=nc=0,ia=ib=ic=1;
		ans=0;
		nn=n;
		memset(vis,0,sizeof(vis));
		for (int i=1; i<=n; i++)
			scanf("%d%d%d",&a[i].val,&b[i].val,&c[i].val),a[i].id=b[i].id=c[i].id=i;
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		while (n)
			fa(),fb(),fc();
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
