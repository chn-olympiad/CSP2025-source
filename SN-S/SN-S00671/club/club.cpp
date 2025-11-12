//SN-S00617 贾章泽 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int t,n,f[105][105][105];
struct qzr{
	int a;
	int a1;
	int a2;
	int a3;
	bool operator <(qzr wnn) const{
		return a>wnn.a;
	}
}dp[100005][5];
struct jmc{
	int a1;
	int a2;
	int a3;
	int st;
	int nd;
	int rd;
	bool operator <(jmc tjr) const{
		return st>tjr.st||(st==tjr.st&&nd>tjr.nd)||(st==tjr.st&&nd==tjr.nd&&rd>tjr.rd);
	}
}a[100005];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		int x[5];
		x[1]=a[i].a1;
		x[2]=a[i].a2;
		x[3]=a[i].a3;
		sort(x+1,x+4);
		a[i].st=x[3];
		a[i].nd=x[2];
		a[i].rd=x[1];
	}
//	if(n<=200){
//		int ans=0;
////		f[0][1][1]=a[]
//		for(int i=0;i<=n/2;i++){
//			for(int j=0;j<=n/2;j++){
//				for(int k=0;k<=n/2;k++){
//					if(i!=0) f[i][j][k]=max(f[i-1][j][k]+a[i+j+k].a1,f[i][j-1][k]+a[i+j+k].a2),f[i][j][k-1]+a[i+j+k].a3);
//					if(j!=0)f[i][j][k]=max(max(f[i-1][j][k]+a[i+j+k].a1,f[i][j-1][k]+a[i+j+k].a2),f[i][j][k-1]+a[i+j+k].a3);
//					if(k!=0)f[i][j][k]=max(max(f[i-1][j][k]+a[i+j+k].a1,f[i][j-1][k]+a[i+j+k].a2),f[i][j][k-1]+a[i+j+k].a3);
////					cout<<f[i][j][k]<<endl;
//				}
//			}
//		}
//		for(int i=0;i<=n/2;i++){
//			for(int j=0;j<=n/2;j++){
//				for(int k=0;k<=n/2;k++){
//					if(i+j+k==n) ans=max(ans,f[i][j][k]);
//				}
//			}
//		}
//		cout<<ans<<"\n";
//		return;
//	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qzr x[5];
		x[1]=dp[i-1][1];
		x[2]=dp[i-1][2];
		x[3]=dp[i-1][3];
		sort(x+1,x+4);
		if(x[1].a1<n/2){
			dp[i][1]=x[1];
			dp[i][1].a+=a[i].a1;
			dp[i][1].a1++;
		}else if(x[2].a1<n/2){
//			cout<<endl<<x[1].a<<" "<<x[2].a<<" "<<x[3].a<<endl;
			dp[i][1]=x[2];
			dp[i][1].a+=a[i].a1;
			dp[i][1].a1++;
		}else{
			dp[i][1]=x[3];
			dp[i][1].a+=a[i].a1;
			dp[i][1].a1++;
		}
		
		if(x[1].a2<n/2){
			dp[i][2]=x[1];
			dp[i][2].a+=a[i].a2;
			dp[i][2].a2++;
		}else if(x[2].a2<n/2){
			dp[i][2]=x[2];
			dp[i][2].a+=a[i].a2;
			dp[i][2].a2++;
		}else{
			dp[i][2]=x[3];
			dp[i][2].a+=a[i].a2;
			dp[i][2].a2++;
		}
		
		if(x[1].a3<n/2){
			dp[i][3]=x[1];
			dp[i][3].a+=a[i].a3;
			dp[i][3].a3++;
		}else if(x[2].a3<n/2){
			dp[i][3]=x[2];
			dp[i][3].a+=a[i].a3;
			dp[i][3].a3++;
		}else{
			dp[i][3]=x[3];
			dp[i][3].a+=a[i].a3;
			dp[i][3].a3++;
		}
	}
//	cout<<dp[n][1].a1<<" "<<dp[n][1].a2<<" "<<dp[n][1].a3<<" "<<dp[n][1].a<<endl;
//	cout<<dp[n][2].a1<<" "<<dp[n][2].a2<<" "<<dp[n][2].a3<<" "<<dp[n][2].a<<endl;
//	cout<<dp[n][3].a1<<" "<<dp[n][3].a2<<" "<<dp[n][3].a3<<" "<<dp[n][3].a<<endl;
	cout<<max(max(dp[n][1].a,dp[n][2].a),dp[n][3].a)<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
}
//wc怎么T1还没过 17:32 
