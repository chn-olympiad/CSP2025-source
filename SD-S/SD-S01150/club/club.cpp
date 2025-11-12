#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,mx=0;
struct node{
	int a,b,c;
	bool operator < (const node&other) const {
		if(a!=other.a)
			return a>other.a;
		if(b!=other.b)
			return b>other.b;
		return c<other.c;
	}
}a[N];
struct rp{
	int num,c1,c2,c3;
}dp[N];
void dfs(int t,int ca,int cb,int cc,int sum){
	if(ca>n/2||cb>n/2||cc>n/2)
		return;
	if(t>n){
		mx=max(mx,sum);
		return;
	}
	dfs(t+1,ca+1,cb,cc,sum+a[t].a);
	dfs(t+1,ca,cb+1,cc,sum+a[t].b);
	dfs(t+1,ca,cb,cc+1,sum+a[t].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool special_2_0=1;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b>0||a[i].c>0)
				special_2_0=0;
		}
		if(n<=15){
			mx=0;
			dfs(1,0,0,0,0);
			printf("%d\n",mx);
			continue;
		}
		if(special_2_0==1){
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=1;i<=n/2;++i)
				ans+=a[i].a;
			printf("%d\n",ans);
			return 0;
		}
//		sort(a+1,a+n+1);
//		int ans=0,c1=0,c2=0,c3=0,ans2=0;
//		for(int i=1;i<=n;++i){
//			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a&&c1<n/2)
//				c1++,ans+=a[i].a;
//			else if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b&&c2<n/2)
//				c2++,ans+=a[i].b;
//			else if(max(a[i].a,max(a[i].b,a[i].c))==a[i].c&&c3<n/2)
//				c3++,ans+=a[i].c;
//			else if(a[i].a>=min(a[i].b,a[i].c)&&a[i].a<=max(a[i].b,a[i].c)&&c1<n/2)
//				c1++,ans+=a[i].a;
//			else if(a[i].b>=min(a[i].a,a[i].c)&&a[i].b<=max(a[i].a,a[i].c)&&c2<n/2)
//				c2++,ans+=a[i].b;
//			else if(a[i].c>=min(a[i].a,a[i].b)&&a[i].c<=max(a[i].a,a[i].b)&&c3<n/2)
//				c3++,ans+=a[i].c;
//			else if(min(a[i].a,min(a[i].b,a[i].c))==a[i].a&&c1<n/2)
//				c1++,ans+=a[i].a;
//			else if(min(a[i].a,min(a[i].b,a[i].c))==a[i].b&&c2<n/2)
//				c2++,ans+=a[i].b;
//			else if(min(a[i].a,min(a[i].b,a[i].c))==a[i].c&&c3<n/2)
//				c3++,ans+=a[i].c;
//		}
		memset(dp,0,sizeof(0));
		for(int i=1;i<=n;++i){
			dp[i].num=dp[i-1].num,dp[i].c1=dp[i-1].c1,dp[i].c2=dp[i-1].c2,dp[i].c3=dp[i-1].c3;
			if(dp[i-1].c1<n/2&&dp[i-1].num+a[i].a>dp[i].num)
				dp[i].num=dp[i-1].num+a[i].a,dp[i].c1=dp[i-1].c1+1,dp[i].c2=dp[i-1].c2,dp[i].c3=dp[i-1].c3;
			if(dp[i-1].c2<n/2&&dp[i-1].num+a[i].b>dp[i].num)
				dp[i].num=dp[i-1].num+a[i].b,dp[i].c2=dp[i-1].c2+1,dp[i].c1=dp[i-1].c1,dp[i].c3=dp[i-1].c3;
			if(dp[i-1].c3<n/2&&dp[i-1].num+a[i].c>dp[i].num)
				dp[i].num=dp[i-1].num+a[i].c,dp[i].c3=dp[i-1].c3+1,dp[i].c1=dp[i-1].c1,dp[i].c2=dp[i-1].c2;
		}
		printf("%d\n",dp[n].num);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
