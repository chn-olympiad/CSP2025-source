#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,T;
struct clas{
	int a1;
	int a2;
	int a3;
}a[N];
int dp[40][40][40][40];
bool cmp(clas aa,clas bb){
	return aa.a1>bb.a1;
}
bool cmp2(clas aa,clas bb){
	if(max(aa.a1,max(aa.a2,aa.a3))!=max(bb.a1,max(bb.a2,bb.a3))){
		return max(aa.a1,max(aa.a2,aa.a3))<max(bb.a1,max(bb.a2,bb.a3));
	}
	else if(aa.a1+aa.a2+aa.a3-max(aa.a1,max(aa.a2,aa.a3))-min(aa.a1,min(aa.a2,aa.a3))!=bb.a1+bb.a2+bb.a3-max(bb.a1,max(bb.a2,bb.a3))-min(bb.a1,min(bb.a2,bb.a3))){
		return aa.a1+aa.a2+aa.a3-max(aa.a1,max(aa.a2,aa.a3))-min(aa.a1,min(aa.a2,aa.a3))<bb.a1+bb.a2+bb.a3-max(bb.a1,max(bb.a2,bb.a3))-min(bb.a1,min(bb.a2,bb.a3));
	}
	else return min(aa.a1,min(aa.a2,aa.a3))<min(bb.a1,min(bb.a2,bb.a3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n>=200){
			bool t=1,f=1;
			for(int i=1;i<=n;i++){
				if(a[i].a2!=0||a[i].a3!=0){
					t=0;
				}
				if(a[i].a3!=0){
					f=0; 
				}
			}
			if(t==1){
				int ans=0;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a1;
				}
				cout<<ans<<endl;
			}
			else{
				sort(a+1,a+n+1,cmp);
				int A=0,B=0,C=0;
				int al=0,bl=0,cl=0;
				int lim=n/2;
				for(int i=1;i<=n;i++){
				if(a[i].a1>=max(a[i].a2,a[i].a3)){
					if(A!=lim){
						A++;
						al+=a[i].a1; 
					}
					else if(a[i].a3>a[i].a2&&C!=lim){
						C++;
						cl+=a[i].a3;
					}
					else{
						B++;
						bl+=a[i].a2;
					} 
				}
				else if(a[i].a2>=max(a[i].a1,a[i].a3)){
					if(B!=lim){
						B++;
						bl+=a[i].a2; 
					}
					else if(a[i].a3>a[i].a1&&C!=lim){
						C++;
						cl+=a[i].a3;
					}
					else{
						A++;
						al+=a[i].a1;
					} 
				}
				else if(a[i].a3>=max(a[i].a1,a[i].a2)){
					if(C!=lim){
						C++;
						cl+=a[i].a3; 
					}
					else if(a[i].a1>a[i].a2&&A!=lim){
						A++;
						al+=a[i].a1;
					}
					else{
						B++;
						bl+=a[i].a2;
					} 
				}
			}
			cout<<al+bl+cl<<endl; 
			}
		}
		else{
			for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int w=n/2;w>=0;w--){
						if(j+k+w<=n){
							if(j+1<=n/2) dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j+1][k][w]+a[i].a1);
							if(k+1<=n/2) dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j][k+1][w]+a[i].a2);
							if(w+1<=n/2) dp[i][j][k][w]=max(dp[i][j][k][w],dp[i-1][j][k][w+1]+a[i].a3);
						}
					}
				}
			}
		} 		
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int w=n/2;w>=0;w--){
						ans=max(dp[i][j][k][w],ans);
					}
				}
			}
		} 
		cout<<ans<<endl; 
		}
	} 
	return 0;
}