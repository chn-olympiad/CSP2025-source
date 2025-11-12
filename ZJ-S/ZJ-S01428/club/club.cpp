//55 -> 60 -> 70
#include<bits/stdc++.h>
using namespace std;
int T,n,dp[205][205][205],v1[100005],v2[100005];
struct node{
	int s1,s2,s3;
}a[100005];
bool cmp(node x,node y){
	return x.s1>y.s1;
}
bool cmp1(int x,int y){
	return a[x].s1-a[x].s2<a[y].s1-a[y].s2;
}
bool cmp2(int x,int y){
	return a[x].s2-a[x].s1<a[y].s2-a[y].s1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;++i){
				cin>>a[i].s1>>a[i].s2>>a[i].s3;
			}
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;++i){
				for(int j=0;j<=i&&j<=n/2;++j){
					for(int k=0;k+j<=i&&k<=n/2;++k){
						if(j) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i].s1);
						if(k) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+a[i].s2);
						if(i-j-k) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+a[i].s3);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n/2;++i){
				for(int j=1;j<=n/2;++j){
					int k=n-i-j;
					if(k<=n/2) ans=max(ans,dp[i][j][k]);
				}
			}
			cout<<ans<<endl;
		}else{
			bool f=0;
			for(int i=1;i<=n;++i){
				cin>>a[i].s1>>a[i].s2>>a[i].s3;
				if(a[i].s2!=0){
					f=1;
				}
			}
			if(!f){
				sort(a+1,a+1+n,cmp);
				int ans=0;
				for(int i=1;i<=n/2;++i) ans+=a[i].s1;
				cout<<ans<<endl;
			}else{
				int sum1=0,sum2=0,tot1=0,tot2=0,ans=0;
				for(int i=1;i<=n;++i){
					if(a[i].s1>=a[i].s2){
						sum1++;
						v1[++tot1]=i;
						ans+=a[i].s1;
					}else{
						sum2++;
						v2[++tot2]=i;
						ans+=a[i].s2;
					}
				}
				if(sum1==sum2){
					cout<<ans<<endl;
				}else if(sum1>sum2){
					sort(v1+1,v1+tot1+1,cmp1);
					for(int i=1;i<=tot1-n/2;++i){
						ans-=(a[v1[i]].s1-a[v1[i]].s2);
					}
					cout<<ans<<endl;
				}else{
					sort(v2+1,v2+tot2+1,cmp2);
					for(int i=1;i<=tot2-n/2;++i){
						ans-=(a[v2[i]].s2-a[v2[i]].s1);
					}
					cout<<ans<<endl;
				}
			}
			
		}
		
	}
	return 0;
}

