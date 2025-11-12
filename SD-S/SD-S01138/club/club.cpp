//#include<bits/stdc++.h>
//using namespace std;
//const long long N=100005;
//long long n,maxn/*n/2*/,a[N][4],club1[N],club2[N],club3[N],ans;
//long long qs[N];
//int T;
//bool cmp(int x,int y){
//	return x>y;
//}
//int main(){
//	cin>>T;
//	while(T--){
//		ans=0;
//		memset(qs,0,sizeof(qs));
//		cin>>n;
//		maxn=n/2;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cin>>a[i][j];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			club1[i]=a[i][1];
//		}
//		for(int i=1;i<=n;i++){
//			club2[i]=a[i][2];
//		}
//		for(int i=1;i<=n;i++){
//			club3[i]=a[i][3];
//		}
//		sort(club1+1,club1+1+n,cmp);
//		sort(club2+1,club2+1+n,cmp);
//		sort(club3+1,club3+1+n,cmp);
//		for(int i=1;i<=n/2;i++){
//			qs[i]=club1[i];
//		}
//		for(int i=1;i<=n/2;i++){
//			qs[n/2+i]=club2[i];
//		}
//		for(int i=1;i<=n/2;i++){
//			qs[n+i]=club3[i];
//		}
//		sort(qs+1,qs+(n/2)*3+1,cmp);
//		for(int i=1;i<=n;i++){
//			ans+=qs[i];
//		}
//		cout<<ans<<endl;
//	}
//		return 0;
//} 
//#include<bits/stdc++.h>
//using namespace std;
//const long long N=100005;
//long long n,maxn/*n/2*/,a[N][4],dp[N][4],c1,c2,c3;
//struct mm{
//	int a=0;
//};
//mm dp[N][4];
//int main(){
//	cin>>n;
//	maxn=n/2;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cin>>a[i][j];
//		}	
//	}
//	for(int j=1;j<=3;j++){
//		dp[1][j]=a[1][j];
//	}
//	c1=1;
//	c2=1;
//	c3=1;
//	for(int i=2;i<=n;i++){
//		if((dp[i-1][1]>dp[i-1][2])&&(dp[i-1][1]>dp[i-1][3])){
//			if(c1==maxn){
//				if(c2==maxn){
////					dp[i][1]=a[i][1]+dp[i-1][3];
////					dp[i][2]=a[i][2]+dp[i-1][3];
//					dp[i][3]=a[i][3]+dp[i-1][3];
//					c3++;
//				}
//				if(c3==maxn){
////					dp[i][1]=a[i][1]+dp[i-1][2];
//					dp[i][2]=a[i][2]+dp[i-1][2];
//					c2++;
////					dp[i][3]=a[i][3]+dp[i-1][2];
//				}
//				else if(dp[i-1][2]>dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][2];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][2];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][2];
//					c3++;
//				}
//				else if(dp[i-1][2]<dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][3];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][3];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][3];
//					c3++;
//				}
//				else if(dp[i-1][2]==dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][2];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][2];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][2];
//					c3++;
//				}
//			}
//			else {
//				dp[i][1]=a[i][1]+dp[i-1][1];
//				c1++;
//				dp[i][2]=a[i][2]+dp[i-1][1];
//				c2++;
//				dp[i][3]=a[i][3]+dp[i-1][1];
//				c3++;
//			}
//		}
//		
//		
//		if((dp[i-1][2]>dp[i-1][1])&&(dp[i-1][2]>dp[i-1][3])){
//			if(c2==maxn){
//				if(c1==maxn){
//					dp[i][3]=a[i][3]+dp[i-1][3];
//					c3++;
//				}
//				if(c3==maxn){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//				}
//				else if(dp[i-1][1]>dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][1];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][1];
//					c3++;
//				}
//				else if(dp[i-1][1]<dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][3];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][3];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][3];
//					c3++;
//				}
//				else if(dp[i-1][1]==dp[i-1][3]){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][1];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][1];
//					c3++;
//				}
//			}
//			else {
//				dp[i][1]=a[i][1]+dp[i-1][2];
//				c1++;
//				dp[i][2]=a[i][2]+dp[i-1][2];
//				c2++;
//				dp[i][3]=a[i][3]+dp[i-1][2];
//				c3++;
//			}
//	}
//		if((dp[i-1][3]>dp[i-1][2])&&(dp[i-1][3]>dp[i-1][1])){
//			if(c3==maxn){
//				if(c2==maxn){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//				}
//				if(c1==maxn){
//					dp[i][2]=a[i][2]+dp[i-1][2];
//					c2++;
//				}
//				if(dp[i-1][1]>dp[i-1][2]){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][1];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][1];
//					c3++;
//				}
//				if(dp[i-1][1]<dp[i-1][2]){
//					dp[i][1]=a[i][1]+dp[i-1][2];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][2];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][2];
//					c3++;
//				}
//				if(dp[i-1][2]==dp[i-1][1]){
//					dp[i][1]=a[i][1]+dp[i-1][1];
//					c1++;
//					dp[i][2]=a[i][2]+dp[i-1][1];
//					c2++;
//					dp[i][3]=a[i][3]+dp[i-1][1];
//					c3++;
//				}
//			}
//			else {
//				dp[i][1]=a[i][1]+dp[i-1][3];
//				c1++;
//				dp[i][2]=a[i][2]+dp[i-1][3];
//				c2++;
//				dp[i][3]=a[i][3]+dp[i-1][3];
//				c3++;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cout<<dp[i][j]<<"  "; 
//		}
//		cout<<endl;
//		cout<<c1<<endl;
//	}
//	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;
long long const N=100005;
int n,a[N][4],T,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans+=a[i][1];
		}
		cout<<ans;
	}
	return 0;
} 
