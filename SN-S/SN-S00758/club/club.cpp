#include<bits/stdc++.h>
using namespace std;
//struct Node{
//	int t[5];
//}a[100005];
int t,n,ans,v[5],a[100005][5],b[100005],c[100005],dp[105][105][105],dp1[205][105][105];
//queue <int> q[5];
//bool cmp(Node x,Node y){
//	return x.t[0]>y.t[0];
//}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			b[i]=b[i-1]+a[2][i];
			c[i]=c[i-1]+a[3][i];
		}
		if(b[n]==0 && c[n]==0){
			sort(a[1]+1,a[1]+n+1,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[1][i];
			cout<<ans;
//			continue;
		}
		else{
			memset(dp,0,sizeof(dp));
			for(int y=1;y<=n;y++)
				for(int i=n/2;i>=1;i--)
					for(int j=n/2;j>=1;j--)
						for(int k=n/2;k>=1;k--)
							dp[i][j][k]=max(dp[i][j][k],max(dp[i][j][k-1]+a[3][y],max(dp[i-1][j][k]+a[1][y],dp[i][j-1][k]+a[2][y])));
	//		for(int i=1;i<=n/2;i++)
	//			for(int j=1;j<=n/2;j++)
	//				for(int k=1;k<=n/2;k++)
	//					ans=max(ans,dp[i][j][k]);
			cout<<dp[n/2][n/2][n/2];			
		}
	}
	return 0;
}
//		for(int i=1;i<=n;i++){
//			cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3],a[i].t[0]=max(a[i].t[0],max(a[i].t[1],max(a[i].t[2],a[i].t[3])));
//			for(int j=1;j<=3;j++)
//				if(a[i].t[j]==a[i].t[0])
//					a[i].t[4]=j;
//		}
//		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			if(a[i].t[1]==a[i].t[2] && a[i].t[2]==a[i].t[3])
//				q[1].push(i),q[2].push(i),q[3].push(i);
//			else for(int j=1;j<=2;j++)
//				for(int k=i+1;k<=3;k++)
//					if(a[i].t[j]==a[i].t[0] && a[i].t[j]==a[i].t[k])
//						q[j].push(i),q[k].push(i);
//			if(v[a[i].t[4]]<n/2)
//				v[a[i].t[4]]++,ans+=a[i].t[0];
//			else{
//				
//			}
//		}
//for(int i=1;i<=n;i++)
//	for(int j=W;j>=w[i];j--)
//		dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
