#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
int m1[maxn],m2[maxn],m3[maxn];
int tong1[maxn],tong2[maxn],tong3[maxn];
int dp[maxn];
bool cmp1(int a,int b){
	return a>b;
}
int solve1(int n){
	int num1=0,num2=0,num3=0;
	for(int i=1;i<=n;i++){
		if(num1<n/2){
			if(num2<n/2){
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[i],max(dp[i-1]+m2[i],dp[i-1]+m3[i]));
					if(dp[i]-x==m1[i])num1++;
					else if(dp[i]-x==m2[i])num2++;
					else num3++;
				}else{
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[i],dp[i-1]+m2[i]);
					if(dp[i]-x==m1[i])num1++;
					else num2++;
				}
			}else{
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[i],dp[i-1]+m3[i]);
					if(dp[i]-x==m1[i])num1++;
					else num3++;
				}else{
					dp[i]=dp[i-1]+m1[i];
					num1++;
				}
			}
		}else{
			if(num2<n/2){
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m2[i],dp[i-1]+m3[i]);
					if(dp[i]-x==m2[i])num2++;
					else num3++;
				}else{
					dp[i]=dp[i-1]+m2[i];
					num2++;
				}
			}else{
				if(num3<n/2){
					dp[i]=dp[i-1]+m3[i];
					num3++;
				}
			}
		}	
	}
	return dp[n];
}
int solve2(int n){
	int num1=0,num2=0,num3=0;
	for(int i=1;i<=n;i++){
		int j=n-i+1;
		if(num1<n/2){
			if(num2<n/2){
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[j],max(dp[i-1]+m2[j],dp[i-1]+m3[j]));
					if(dp[i]-x==m1[j])num1++;
					else if(dp[i]-x==m2[j])num2++;
					else num3++;
				}else{
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[j],dp[i-1]+m2[j]);
					if(dp[i]-x==m1[j])num1++;
					else num2++;
				}
			}else{
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m1[j],dp[i-1]+m3[j]);
					if(dp[i]-x==m1[j])num1++;
					else num3++;
				}else{
					dp[i]=dp[i-1]+m1[j];
					num1++;
				}
			}
		}else{
			if(num2<n/2){
				if(num3<n/2){
					int x=dp[i-1];
					dp[i]=max(dp[i-1]+m2[j],dp[i-1]+m3[j]);
					if(dp[i]-x==m2[j])num2++;
					else num3++;
				}else{
					dp[i]=dp[i-1]+m2[j];
					num2++;
				}
			}else{
				if(num3<n/2){
					dp[i]=dp[i-1]+m3[j];
					num3++;
				}
			}
		}	
	}
	return dp[n];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m1[i]>>m2[i]>>m3[i];
			tong1[m1[i]]++;
			tong2[m2[i]]++;
			tong3[m3[i]]++;
		}
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		int ans=0;
		if(tong1[0]==n){
			if(tong2[0]==n){
				sort(m3+1,m3+n+1,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=m3[i];
				}
			}
			if(tong3[0]==n){
				sort(m2+1,m2+n+1,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=m2[i];
				}
			}
		}else{
			if(tong2[0]==n&&tong3[0]==n){
				sort(m1+1,m1+n+1,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=m1[i];
				}
			}
		}
		if(ans!=0)cout<<ans<<'\n';
		else{
			cout<<max(solve1(n),solve2(n))<<'\n';
		}
	}
	return 0;
}
