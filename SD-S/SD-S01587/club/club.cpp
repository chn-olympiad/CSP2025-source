#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#define qqq printf("------ qqq ------\n");
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int K=1e4+10;
const int M=2e2+10;
ll T,n,ans;
ll a[N][5];
ll dp[M][M/2][M/2];
//ll dfs(ll x,ll _1,ll _2,ll _3){
//	if(x==n+1){
//		return 0;
//	}
//	ll res=0;
//	if(_1+1<=n/2)	res=max(res,dfs(x+1,_1+1,_2,_3)+a[x][1]);
//	if(_2+1<=n/2)	res=max(res,dfs(x+1,_1,_2+1,_3)+a[x][2]);
//	if(_3+1<=n/2)	res=max(res,dfs(x+1,_1,_2,_3+1)+a[x][3]);
//	return res;
//}
//struct edge{
//	ll id;
//	ll _1,_2;
//	ll su;
//}b[N];
//void fun_1(){
//qqq;//
//	ans=dfs(1,0,0,0);
//	printf("%lld\n",ans);
//qqq;//
//	return ;
//}
//void fun_2(){
//	ans=0;
//	for(ll i=1;i<=n;i++)	cnt[i]=-1;
//	queue<edge>qu;
//	qu.push({1,0,0,0});
//	while(!qu.empty()){
//		edge x=qu.front();
//		ll id=x.id;
//		ll _1=x._1,_2=x._2;
//		ll _3=id-_1-_2;
//		ll su=x.su;
//		if(id==n+1){
//			ans=max(ans,su);
//			qu.pop();
//			continue;
//		}
//		if(_1+1<=n/2)	qu.push({id+1,_1+1,_2,su+a[id][1]});
//		if(_2+1<=n/2)	qu.push({id+1,_1,_2+1,su+a[id][2]});
//		if(_3+1<=n/2)	qu.push({id+1,_1,_2,su+a[id][3]});
//		qu.pop();
//	}
//	printf("%lld\n",ans);
//qqq;//
//	return ;
//}
void fun_3(){
	ans=0;
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=n;i++){
		for(ll _1=0;_1<=n/2;_1++){
			for(ll _2=0;_2<=n/2;_2++){
				ll _3=i-_1-_2;
				if(_3>n/2)	continue;
				if(_1-1>=0)	dp[i][_1][_2]=max(dp[i][_1][_2],dp[i-1][_1-1][_2]+a[i][1]);
				if(_2-1>=0)	dp[i][_1][_2]=max(dp[i][_1][_2],dp[i-1][_1][_2-1]+a[i][2]);
				if(_3-1>=0)	dp[i][_1][_2]=max(dp[i][_1][_2],dp[i-1][_1][_2]+a[i][3]);
				if(i==n)	ans=max(ans,dp[i][_1][_2]);
			}
		}
	}
	printf("%lld\n",ans);
//qqq;//
	return ;
}
ll dp2[N][5][5];
/*
dp2[i][j][0]：i个选择j的最大答案
dp2[i][j][1]：i个选择j的1社团的人数
dp2[i][j][2]：i个选择j的2社团的人数
dp2[i][j][3]：i个选择j的3社团的人数 
*/
void fun_4(){
	ans=0;
	ll k=n/2;
	memset(dp2,0,sizeof(dp2));
	dp2[1][1][0]=a[1][1],dp2[1][1][1]=1;
	dp2[1][2][0]=a[1][2],dp2[1][2][2]=1;
	dp2[1][3][0]=a[1][3],dp2[1][3][3]=1;
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<=3;j++){
			ll w=1;
			for(ll f=1;f<=3;f++){
				if(dp2[i-1][f][j]+1<=k)
					if(dp2[i-1][f][0]+a[i][j]>dp2[i][j][0])
						dp2[i][j][0]=dp2[i-1][f][0]+a[i][j],w=f;
			}
			dp2[i][j][1]=dp2[i-1][w][1];
			dp2[i][j][2]=dp2[i-1][w][2];
			dp2[i][j][3]=dp2[i-1][w][3];
			dp2[i][w][w]++;
		}
	}
	ans=max(max(dp2[n][1][0],dp2[n][2][0]),dp2[n][3][0]);
	printf("%lld\n",ans);
//qqq;//
	return ;
}
struct node{
	ll u,v,w;
}t[N];
bool cmp(node x,node y){
	return (x.u>y.u);
}
void fun(){
	scanf("%lld",&n);
	bool fl2=0,fl3=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		t[i].u=a[i][1],t[i].v=a[i][2],t[i].w=a[i][3];
		if(a[i][2]!=0)	fl2=1;
		if(a[i][3]!=0)	fl3=1;
	}
	if(fl2==0&&fl3==0){
		sort(t+1,t+n+1,cmp);
		ans=0;
		for(ll i=1;i<=n/2;i++)
			ans+=t[i].u;
		printf("%lld\n",ans);
//qqq;
		return ;
	}
//	fun_1();
//	fun_2();
	if(n<=200)
		fun_3();
	else
		fun_4();
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)	fun();
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

18
4
13
*/
