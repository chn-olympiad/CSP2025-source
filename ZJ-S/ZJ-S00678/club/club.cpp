#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,vis[N],dp[210][210][210],ans;
struct node{
	int x,y,z,cha;
}a[N],b[N];
bool cmp1(node a,node b){
	return a.x>b.x;
}bool cmp2(node a,node b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		
		cin>>n;
		int tmp2=1,tmp3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].cha=a[i].x-a[i].y;
		}
		if(n<=400){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int x=0;x<=i&&x<=n/2;x++){
					for(int y=0;y<=i-x&&y<=n/2;y++){
						int z=i-x-y;
						if(z>0)
							dp[i][x][y]=dp[i-1][x][y]+a[i].z;
						if(x>0){
							dp[i][x][y]=max(dp[i][x][y],dp[i-1][x-1][y]+a[i].x);
						}if(y>0){
							dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+a[i].y);
						}
					}
				}
			}int ans=0;
			for(int x=0;x<=n/2;x++){
				for(int y=0;y<=n/2;y++){
					int z=n-x-y;
					if(x<=n/2&&y<=n/2&&z<=n/2)
					ans=max(ans,dp[n][x][y]);
				}
			}cout<<ans<<endl;
		}else if(tmp2&&tmp3){
			int ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=n;i>=n/2+1;i--){
				ans+=a[i].x;
			}cout<<ans<<endl;
		}else if(tmp3){
			int ans=0,mx=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				ans+=a[i].y;
			}for(int i=1,cnt1=0,cnt2=n;i<=n;i++){
				
				ans-=a[i].y;
				ans+=a[i].x;
				cnt1++;
				cnt2--;
				if(cnt1<=n/2&&cnt2<=n/2)
				mx=max(mx,ans);
			}cout<<mx<<endl;
		}
	}
	
	return 0;
}
