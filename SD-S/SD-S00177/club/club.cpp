#include<bits/stdc++.h>//25pts (1-4,12)
#define int long long
#define S second
#define F first
using namespace std;
int T,n,a[100005][5],b[100005];
bool cmp(int A,int B){//30的极限情况跑2.5天,n最大18 
	return A>B;
}
int dfs(int y1,int y2,int y3,int sum,int prej){
	if(prej>n){
		return sum;
	}
	if(prej==0){
		return max(dfs(y1+1,y2,y3,a[1][1],2),max(dfs(y1,y2+1,y3,a[1][2],2),dfs(y1,y2,y3+1,a[1][3],2)));
	}
	int ans=0;
	if(y1+1<=n/2){
		ans=max(ans,dfs(y1+1,y2,y3,sum+a[prej][1],prej+1));
	}
	if(y2+1<=n/2){
		ans=max(ans,dfs(y1,y2+1,y3,sum+a[prej][2],prej+1));
	}
	if(y3+1<=n/2){
		ans=max(ans,dfs(y1,y2,y3+1,sum+a[prej][3],prej+1));
	}
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		int RT=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			RT+=a[i][2]+a[i][3];
		}
		if(RT==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i]; 
			}
			printf("%lld\n",ans);
		}
		else{
			printf("%lld\n",dfs(0,0,0,0,0));
		} 
	}
	return 0;
}
