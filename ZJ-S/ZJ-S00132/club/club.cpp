#include<bits/stdc++.h>
using namespace std;
int n,_;
long long ans=-1;
struct P{
	int a,b,c;
}a[100005];
void dfs(int la,int lb,int lc,long long lst,int i){
	if(i==n+1){
		ans=max(ans,lst);
		return;
	}
	if(la<n/2) dfs(la+1,lb,lc,lst+a[i].a,i+1);
	if(lb<n/2) dfs(la,lb+1,lc,lst+a[i].b,i+1);
	if(lc<n/2) dfs(la,lb,lc+1,lst+a[i].c,i+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		ans=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c); 
		dfs(0,0,0,0,1);
		printf("%lld\n",ans);
	}
	return 0;
}
