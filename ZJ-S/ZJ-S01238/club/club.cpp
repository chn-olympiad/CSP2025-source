#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n;
ll dp[124][124][124];
struct node{
	ll a,b,c;
}l[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
void solve(){
	scanf("%d",&n);ll ans=0;
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&l[i].a,&l[i].b,&l[i].c);
	if(n>200){
		sort(l+1,l+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=l[i].a;
	}
	else{
		int nn=n/2;
		for(int a=0;a<=nn;++a){
			for(int b=0;b<=nn;++b){
				for(int c=0;c<=nn;++c)dp[a][b][c]=0;
			}
		}
		for(int i=1;i<=n;++i){
			for(int a=nn;a>=0;--a){
				for(int b=min(nn,i-a);b>=0;--b){
					for(int c=min(nn,i-a-b);c>=0;--c){
						if(a-1>=0)dp[a][b][c]=max(dp[a][b][c],dp[a-1][b][c]+l[i].a);
						if(b-1>=0)dp[a][b][c]=max(dp[a][b][c],dp[a][b-1][c]+l[i].b);
						if(c-1>=0)dp[a][b][c]=max(dp[a][b][c],dp[a][b][c-1]+l[i].c);
					}
				}
			}
		}
		for(int a=1;a<=nn;++a){
			for(int b=1;b<=nn;++b){
				ans=max(ans,dp[a][b][n-a-b]);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
} 
