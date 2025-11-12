#include<bits/stdc++.h> 
using namespace std;
int t,n;
struct stu{
	int f1,f2,f3;
}a[2005];
long long ans;
bool cmp1(stu x,stu y){
	return x.f1>y.f1;
}
long long dp[35][35][35][35];
long long f[205][105][105];
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin>> a[i].f1 >> a[i].f2 >> a[i].f3;
		}
		if (n<=30){
			ans=0;
		    for (int i=1;i<=n;i++){
			    for (int j=0;j<=min(i,n/2);j++){
				    for (int k=0;k<=min(i,n/2);k++){
					    int m=i-j-k;
					    dp[i][j][k][m]=0;
				    }
			    }
		    }
		    for (int i=1;i<=n;i++){
		        for (int j1=0;j1<=min(i,n/2);j1++){
				    for (int j2=0;j2<=min(i,n/2);j2++){
					    int j3=i-j1-j2;
					    if(j3>n/2)continue;
					    if (j3)dp[i][j1][j2][j3]=max(dp[i-1][j1][j2][j3-1]+a[i].f3,dp[i][j1][j2][j3]);
					    if (j2)dp[i][j1][j2][j3]=max(dp[i-1][j1][j2-1][j3]+a[i].f2,dp[i][j1][j2][j3]);
					    if (j1)dp[i][j1][j2][j3]=max(dp[i-1][j1-1][j2][j3]+a[i].f1,dp[i][j1][j2][j3]);
					    ans=max(ans,dp[i][j1][j2][j3]);
			    	}
			    }
		    }
		    cout << ans <<endl;
		}
		if (n<=200&&n>30){
			ans=0;
			for (int i=1;i<=n;i++){
			    for (int j=0;j<=min(i,n/2);j++){
				    int k=i-j;
				    f[i][j][k]=0;
			    }
		    }
		    for (int i=1;i<=n;i++){
		        for (int j1=0;j1<=min(i,n/2);j1++){
					int j2=i-j1;
					if(j2>n/2)continue;
					if (j2)f[i][j1][j2]=max(f[i-1][j1][j2-1]+a[i].f2,f[i][j1][j2]);
					if (j1)f[i][j1][j2]=max(f[i-1][j1-1][j2]+a[i].f1,f[i][j1][j2]);
					ans=max(ans,f[i][j1][j2]);
			    }
		    }
		    cout << ans <<  endl;
		}
		if (n>200){
			sort(a+1,a+n+1,cmp1);
			ans=0;
			int k=0;
			for (int i=1;i<=n;i++){
				if (k<=n/2)ans+=a[i].f1;
				else break;
			}
			cout << ans <<endl; 
		}
	}
	return 0;
} 