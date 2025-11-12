#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf
#define mod
#define maxn 100005
#define int long long
int T,n,a[maxn][3],mx[maxn],cnt[3]; 
std::vector<int> vec[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			int tmp; 
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				mx[i]=0,tmp=std::min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				mx[i]=1,tmp=std::min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			}else{
				mx[i]=2,tmp=std::min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
			}
			ans+=a[i][mx[i]],cnt[mx[i]]++;
			vec[mx[i]].push_back(tmp);
		}
//		printf("dbg %lld\n",ans);
		for(int i=0;i<=2;i++){
			if(cnt[i]>n/2){
				int k=cnt[i]-n/2;
				std::sort(vec[i].begin(),vec[i].end());
				for(int j=0;j<k;j++){
//					printf("%lld ",vec[i][j]);
					ans-=vec[i][j];
				}
			}
			vec[i].clear(),cnt[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/

