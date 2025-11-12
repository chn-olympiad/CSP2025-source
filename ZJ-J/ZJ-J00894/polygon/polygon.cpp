#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define IO
using namespace std;
#define ll long long
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
int n;
int ans[5005];
bool vis[5005];
int a[5005];ll cnt;
//40    O(2^n)
void dfs(int k,int old,int sum){
	if(k>3){
		if(sum-ans[k-1]>ans[k-1]){
			cnt++;
		}
		if(k==n+1)return;
	}
	L(i,old,n){
		if(vis[i])continue;
		ans[k]=a[i];
		vis[i]=1;
		dfs(k+1,i+1,sum+a[i]);
		vis[i]=0;
	}
}
int main(){
#ifdef IO
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	scanf("%d",&n);
	L(i,1,n){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,[](int a,int b){
		return a<b;
	});
//	if(max_element(a+1,a+n+1)==1){//24
//		int k=count(a+1,a+n+1,1);
//		ll ans=0,us=1;
//		L(i,1,k){
//			us*=i;
//			ans+=(us/)
//		}
//		printf("%lld\n",ans);
//		return 0;
//	}
	dfs(1,1,0);
	printf("%lld\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
