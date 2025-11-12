#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,t,cnt[5],maxx,ans,a[N][5];
void dfs(int k){
	if(k==n+1){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1>n/2) continue;
	    else{
	    	cnt[i]++;
	    	ans+=a[k][i];
			dfs(k+1);
			cnt[i]--;
			ans-=a[k][i];
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
    while(t--){
    	scanf("%lld",&n);
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=3;j++){
	    		scanf("%lld",&a[i][j]);
			}
		}
		maxx=0;
		ans=0;
		dfs(1);
		printf("%lld\n",maxx);
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

