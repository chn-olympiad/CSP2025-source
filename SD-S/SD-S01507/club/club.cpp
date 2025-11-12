#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=1e5+5;
int t,n;
ll ans,sum[MAXN];
struct node{
	int x,y,z;
}p[MAXN];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y>b.y;
}
void dfs(ll res,int a,int b,int c,int k){
	if(k==n+1){
		ans=max(ans,res);
		return ;
	}
	if(res+sum[n-k+1]<=ans) return;
	for(int i=k;i<=n;i++){
		if(a<n/2) dfs(res+p[i].x,a+1,b,c,i+1);
		if(b<n/2) dfs(res+p[i].y,a,b+1,c,i+1);
		if(c<n/2) dfs(res+p[i].z,a,b,c+1,i+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		bool flg1=1,flg2=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
			if(p[i].y!=0) flg1=0;
			if(p[i].z!=0) flg2=0;
		}
		if(flg1&&flg2){
			sort(p+1,p+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].x;
			}
		}
		else if(flg2){
			ll res1=0,res2=0;
			sort(p+1,p+1+n,cmp1);
			for(int i=1;i<=n/2;i++) res1+=p[i].x;
			for(int i=n/2+1;i<=n;i++) res1+=p[i].y;
			sort(p+1,p+1+n,cmp2);
			for(int i=1;i<=n/2;i++) res2+=p[i].y;
			for(int i=n/2+1;i<=n;i++)res2+=p[i].x;
			ans=max(res1,res2);
		}
		else{
			for(int i=1;i<=n;i++) sum[i]=sum[i-1]+max(p[n-i+1].x,max(p[n-i+1].y,p[n-i+1].z));
			dfs(0,0,0,0,1);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
