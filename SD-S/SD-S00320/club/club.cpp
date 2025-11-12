/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T,n;
struct aa{
	ll sum;
	int cnt1,cnt2,cnt3;
}dp[N][4];
struct bb{
	ll x,y,z;
}a[N];
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			//cout<<"dp="<<dp[i][3].sum<<endl;
			if(dp[i-1][1].cnt1<n/2){
				if(dp[i][1].sum<dp[i-1][1].sum+a[i].x){
					dp[i][1].sum=dp[i-1][1].sum+a[i].x;
					dp[i][1].cnt1=dp[i-1][1].cnt1+1;
					dp[i][1].cnt2=dp[i-1][1].cnt2;
					dp[i][1].cnt3=dp[i-1][1].cnt3;
				}
			}
			if(dp[i-1][2].cnt1<n/2){
				if(dp[i][1].sum<dp[i-1][2].sum+a[i].x){
					dp[i][1].sum=dp[i-1][2].sum+a[i].x;
					dp[i][1].cnt1=dp[i-1][2].cnt1+1;
					dp[i][1].cnt2=dp[i-1][2].cnt2;
					dp[i][1].cnt3=dp[i-1][2].cnt3;
				}
			}
			if(dp[i-1][3].cnt1<n/2){
				if(dp[i][1].sum<dp[i-1][3].sum+a[i].x){
					dp[i][1].sum=dp[i-1][3].sum+a[i].x;
					dp[i][1].cnt1=dp[i-1][3].cnt1+1;
					dp[i][1].cnt2=dp[i-1][3].cnt2;
					dp[i][1].cnt3=dp[i-1][3].cnt3;
				}
			}
			//
			if(dp[i-1][1].cnt2<n/2){
				if(i==3){
					cout<<"dp="<<dp[i-1][1].sum<<endl;
					cout<<"???1";
				}
				if(dp[i][2].sum<dp[i-1][1].sum+a[i].y){
					if(i==3){
						cout<<"a="<<a[i].y<<endl;
						cout<<dp[i-1][1].sum+a[i].y<<endl;
					}
					dp[i][2].sum=dp[i-1][1].sum+a[i].y;
					if(i==3)cout<<"dpt="<<dp[i][2].sum<<endl;
					dp[i][2].cnt2=dp[i-1][1].cnt2+1;
					dp[i][2].cnt1=dp[i-1][1].cnt1;
					dp[i][2].cnt3=dp[i-1][1].cnt3;
				}
			}
			if(dp[i-1][2].cnt2<n/2){
				if(i==3)cout<<"???2";
				if(dp[i][2].sum<dp[i-1][2].sum+a[i].y){
					dp[i][2].sum=dp[i-1][2].sum+a[i].y;
					dp[i][2].cnt2=dp[i-1][2].cnt2+1;
					dp[i][2].cnt1=dp[i-1][2].cnt1;
					dp[i][2].cnt3=dp[i-1][2].cnt3;
				}
			}
			if(dp[i-1][3].cnt2<n/2){
				if(i==3)cout<<"???3";
				if(dp[i][2].sum<dp[i-1][3].sum+a[i].y){
					if(i==3){
						cout<<"oo="<<dp[i-1][3].sum<<endl;
					}
					dp[i][2].sum=dp[i-1][3].sum+a[i].y;
					dp[i][2].cnt2=dp[i-1][3].cnt2+1;
					dp[i][2].cnt1=dp[i-1][3].cnt1;
					dp[i][2].cnt3=dp[i-1][3].cnt3;
				}
			}
			//
			if(dp[i-1][1].cnt3<n/2){
				if(dp[i][3].sum<dp[i-1][1].sum+a[i].z){
					dp[i][3].sum=dp[i-1][1].sum+a[i].z;
					dp[i][3].cnt3=dp[i-1][1].cnt3+1;
					dp[i][3].cnt2=dp[i-1][1].cnt2;
					dp[i][3].cnt1=dp[i-1][1].cnt1;
				}
			}
			if(dp[i-1][2].cnt3<n/2){
				if(dp[i][3].sum<dp[i-1][2].sum+a[i].z){
					dp[i][3].sum=dp[i-1][2].sum+a[i].z;
					dp[i][3].cnt3=dp[i-1][2].cnt3+1;
					dp[i][3].cnt2=dp[i-1][2].cnt2;
					dp[i][3].cnt1=dp[i-1][2].cnt1;
				}
			}
			if(dp[i-1][3].cnt3<n/2){
				if(dp[i][3].sum<dp[i-1][3].sum+a[i].z){
					dp[i][3].sum=dp[i-1][3].sum+a[i].z;
					dp[i][3].cnt3=dp[i-1][3].cnt3+1;
					dp[i][3].cnt2=dp[i-1][3].cnt2;
					dp[i][3].cnt1=dp[i-1][3].cnt1;
				}
			}
			cout<<dp[i][2].sum<<" "<<dp[i][2].cnt2<<endl;
		}
		ll maxx=0;
		maxx=max(max(maxx,dp[n][1].sum),max(dp[n][2].sum,dp[n][3].sum));
		cout<<"dp[3][2]="<<dp[3][2].sum<<endl;
		cout<<maxx<<endl;
	}
}

















*/
#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
const int N=200;
int T,n;
typedef long long ll;
//
ll dp[N][20][20][20];//第i个时123各占多少
struct aa{
	ll x,y,z;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		//chushihua
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int f=0;f<=n/2;f++){
				for(int s=0;s<=n/2;s++){
					for(int t=0;t<=n/2&&f+s+t<=n;t++){
						if(f>=1&&s+f+t<=n){
							dp[i][f][s][t]=max(dp[i-1][f-1][s][t]+a[i].x,dp[i][f][s][t]);
						}
						if(s>=1&&s+f+t<=n){
							dp[i][f][s][t]=max(dp[i-1][f][s-1][t]+a[i].y,dp[i][f][s][t]);
						}
						if(t>=1&&s+f+t<=n){
							dp[i][f][s][t]=max(dp[i-1][f][s][t-1]+a[i].z,dp[i][f][s][t]);
						}
					}
				}
			}
		}
		ll maxx=0;
		for(int m=1;m<=n;m++){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k<=n) maxx=max(maxx,dp[m][i][j][k]);
				}
			}
		}
		}
		cout<<maxx<<endl;
	}
	return 0;
} 
