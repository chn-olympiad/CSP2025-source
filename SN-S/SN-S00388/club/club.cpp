//SN-S00388
#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],dp[100005][3],sum[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		if(n==2){
			cout<<max(max(max((a1[1]+a2[2]),(a1[2]+a2[1])),max((a1[1]+a3[2]),(a1[2]+a3[1]))),max((a2[1]+a3[2]),(a2[2]+a3[1])))<<endl;
//		}else if(n<=10){
//			for(int i=1;i<=n;i++){
//				int x,y,z;
//				x=max(a1[i],a2[i],a3[i]);
//				z=min(a1[i],a2[i],a3[i]);
//				if(a2[i]<=x and a2[i]>=z){
//					y=a2[i];
//				}else if(a1[i]<=x and a1[i]>=z){
//					y=a1[i];
//				}else{
//					y=a3[i];
//				}
//				if(sum[]==n/2){
//					continue;
//				}
//			}
		}else{
			int ans=0;
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
