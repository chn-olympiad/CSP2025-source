#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c;
}qwe[100005];
bool cmp(node x,node y){
	if(abs(x.a-max(x.b,x.c))==abs(y.a-max(y.b,y.c))){
		if(abs(x.b-max(x.a,x.c))==abs(y.b-max(y.a,y.c)))return abs(x.c-max(x.b,x.a))>abs(y.c-max(y.b,y.a));
		return abs(x.b-max(x.a,x.c))>abs(y.b-max(y.a,y.c));
	}
	return abs(x.a-max(x.b,x.c))>abs(y.a-max(y.b,y.c));
}
int t,n,sum=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&qwe[i].a,&qwe[i].b,&qwe[i].c);
		sort(qwe+1,qwe+n+1,cmp);
		if(n==2)printf("%lld\n",max({qwe[1].a+qwe[2].b,qwe[1].a+qwe[2].c,qwe[1].b+qwe[2].a,qwe[1].b+qwe[2].c,qwe[1].c+qwe[2].a,qwe[1].c+qwe[2].b}));
		else{
			int w=n/2,z=n/2,x=n/2;
			for(int i=1;i<=n;i++){
				int ans=-1;
				if(w>0)ans=max(ans,qwe[i].a);
				if(z>0)ans=max(ans,qwe[i].b);
				if(x>0)ans=max(ans,qwe[i].c);
				sum+=ans;
				if(ans==qwe[i].a)w--;
				if(ans==qwe[i].b)z--;
				if(ans==qwe[i].c)x--;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//struct node{
//	int a,b,c;
//}qwe[100005];
//bool cmp(node x,node y){
//	if(x.a==y.a){
//		if(x.b==y.b)return x.c>y.c;
//		return x.b>y.b;
//	}
//	return x.a>y.a;
//}
//struct asd{
//	int a,b,c,x;
//}dp[100005][5];
//int t,n,sum=0;
//signed main(){
//	freopen("club2.in","r",stdin);
////	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
//	while(t--){
//		sum=0;
//		scanf("%lld",&n);
//		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&qwe[i].a,&qwe[i].b,&qwe[i].c);
//		if(n==2)printf("%lld\n",max({qwe[1].a+qwe[2].b,qwe[1].a+qwe[2].c,qwe[1].b+qwe[2].a,qwe[1].b+qwe[2].c,qwe[1].c+qwe[2].a,qwe[1].c+qwe[2].b}));
//		else{
//			sort(qwe+1,qwe+n+1,cmp);
//			for(int i=1;i<=n;i++){
//				if(dp[i-1][1].x+qwe[i].a>dp[i][1].x){
//					if(dp[i-1][1].a<n/2)dp[i][1].x=dp[i-1][1].x+qwe[i].a,dp[i][1].a=dp[i-1][1].a+1,dp[i][1].b=dp[i-1][1].b,dp[i][1].c=dp[i-1][1].c;
////					else dp[i][1].x=dp[i-1][1].x,dp[i][1].a=dp[i-1][1].a;
//				}
//				if(dp[i-1][2].x+qwe[i].a>dp[i][1].x){
//					if(dp[i-1][2].a<n/2)dp[i][1].x=dp[i-1][2].x+qwe[i].a,dp[i][1].a=dp[i-1][2].a+1,dp[i][1].b=dp[i-1][2].b,dp[i][1].c=dp[i-1][2].c;
////					else dp[i][1].x=dp[i-1][2].x,dp[i][1].a=dp[i-1][2].a;
//				}
//				if(dp[i-1][3].x+qwe[i].a>dp[i][1].x){
//					if(dp[i-1][3].a<n/2)dp[i][1].x=dp[i-1][3].x+qwe[i].a,dp[i][1].a=dp[i-1][3].a+1,dp[i][1].b=dp[i-1][3].b,dp[i][1].c=dp[i-1][3].c;
////					else dp[i][1].x=dp[i-1][3].x,dp[i][1].a=dp[i-1][3].a;
//				}
//				
//				if(dp[i-1][1].x+qwe[i].b>dp[i][2].x){
//					if(dp[i-1][1].b<n/2)dp[i][2].x=dp[i-1][1].x+qwe[i].b,dp[i][2].b=dp[i-1][1].b+1,dp[i][2].a=dp[i-1][1].a,dp[i][2].c=dp[i-1][1].c;
////					else dp[i][2].x=dp[i-1][1].x,dp[i][2].b=dp[i-1][1].b;
//				}
//				if(dp[i-1][2].x+qwe[i].b>dp[i][2].x){
//					if(dp[i-1][2].b<n/2)dp[i][2].x=dp[i-1][2].x+qwe[i].b,dp[i][2].b=dp[i-1][2].b+1,dp[i][2].a=dp[i-1][2].a,dp[i][2].c=dp[i-1][2].c;
////					else dp[i][2].x=dp[i-1][2].x,dp[i][2].b=dp[i-1][2].b;
//				}
//				if(dp[i-1][3].x+qwe[i].b>dp[i][2].x){
//					if(dp[i-1][3].b<n/2)dp[i][2].x=dp[i-1][3].x+qwe[i].b,dp[i][2].b=dp[i-1][3].b+1,dp[i][2].a=dp[i-1][3].a,dp[i][2].c=dp[i-1][3].c;
////					else dp[i][2].x=dp[i-1][3].x,dp[i][2].b=dp[i-1][3].b;
//				}
//					
//				if(dp[i-1][1].x+qwe[i].c>dp[i][3].x){
//					if(dp[i-1][1].c<n/2)dp[i][3].x=dp[i-1][1].x+qwe[i].c,dp[i][3].c=dp[i-1][1].c+1,dp[i][3].a=dp[i-1][1].a,dp[i][3].b=dp[i-1][1].b;
////					else dp[i][3].x=dp[i-1][1].x,dp[i][3].c=dp[i-1][1].c;
//				}
//				if(dp[i-1][2].x+qwe[i].c>dp[i][3].x){
//					if(dp[i-1][2].c<n/2)dp[i][3].x=dp[i-1][2].x+qwe[i].c,dp[i][3].c=dp[i-1][2].c+1,dp[i][3].a=dp[i-1][2].a,dp[i][3].b=dp[i-1][2].b;
////					else dp[i][3].x=dp[i-1][2].x,dp[i][3].c=dp[i-1][2].c;
//				}
//				if(dp[i-1][3].x+qwe[i].c>dp[i][3].x){
//					if(dp[i-1][3].c<n/2)dp[i][3].x=dp[i-1][3].x+qwe[i].c,dp[i][3].c=dp[i-1][3].c+1,dp[i][3].a=dp[i-1][3].a,dp[i][3].b=dp[i-1][3].b;
////					else dp[i][3].x=dp[i-1][3].x,dp[i][3].c=dp[i-1][3].c;
//				}
//				sum=max({sum,dp[i][1].x,dp[i][2].x,dp[i][3].x});
//			}
////			for(int i=1;i<=n;i++)cout<<dp[i][1].x<<" "<<dp[i][2].x<<" "<<dp[i][3].x<<"!!!\n";
////			for(int i=1;i<=n;i++){
////				cout<<"id1:"<<dp[i][1].a<<" "<<dp[i][2].a<<" "<<dp[i][3].a<<"???\n";
////				cout<<"id2:"<<dp[i][1].b<<" "<<dp[i][2].b<<" "<<dp[i][3].b<<"???\n";
////				cout<<"id3:"<<dp[i][1].c<<" "<<dp[i][2].c<<" "<<dp[i][3].c<<"???\n";
////			}
//			printf("%lld\n",sum);
//			memset(dp,0,sizeof dp);
////			for(int i=1;i<=n;i++)dp[i][1].x=dp[i][1].a=dp[i][1].b=dp[i][1].c=dp[i][2].x=dp[i][2].a=dp[i][2].b=dp[i][2].c=dp[i][3].x=dp[i][3].a=dp[i][3].b=dp[i][3].c=0;
//		}
//	}
//	return 0;
//}