#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],cnt1,cnt2,cnt3,dp1[100020],dp2[100020],dp3[100020];
int r[100010],sum1,sum2,sum3,sum4,sum5,sum6,sum;
//struct node{
//	int a,b,c;
//}dp[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mid=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
   	/*		r[1]=a[i];
			r[2]=b[i];
			r[3]=c[i];
			sort(r+1,r+3+1);
			dp1[i]=r[1];//s
			dp2[i]=r[2];//m
			dp3[i]=r[3];//l
			*/
		}
		for(int i=1;i<n;i++){
		//	sum=max(dp3[i],dp2[i]+dp3[i+1]);
			if(cnt1<mid and cnt2<mid){
				sum1+=max(a[i],b[i]+a[i+1]);
				sum2+=max(b[i],a[i]+b[i+1]);
				sum=max(sum1,sum2);
			}
		}
		cout<<sum<<"\n";
		sum=0;
		sum1=0;
		sum2=0;
	}
	return 0;
}