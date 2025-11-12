#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+6;
int a1[N],a2[N],a3[N];
//int dp[N][4];
int n;
int aa[N];



int dfs(int k,int c1,int c2,int c3,int sum){
	if(k==n) return sum;
	else{
		if(c1==n/2&&c2<n/2&&c3<n/2){
			return max(dfs(k+1,c1,c2+1,c3,sum+a2[k+1]),dfs(k+1,c1,c2,c3+1,sum+a3[k+1]));
		}
		if(c1==n/2&&c2==n/2&&c3<n/2){
			return dfs(k+1,c1,c2,c3+1,sum+a3[k+1]);
		}
		if(c1==n/2&&c2<n/2&&c3==n/2){
			return dfs(k+1,c1,c2+1,c3,sum+a2[k+1]);
		}
		if(c1<n/2&&c2==n/2&&c3==n/2){
			return dfs(k+1,c1+1,c2,c3,sum+a1[k+1]);
		}
		if(c1<n/2&&c2<n/2&&c3<n/2){
			return max(max(dfs(k+1,c1,c2+1,c3,sum+a2[k+1]),dfs(k+1,c1,c2,c3+1,sum+a3[k+1])),dfs(k+1,c1+1,c2,c3,sum+a1[k+1]));
		}
		if(c1<n/2&&c2==n/2&&c3<n/2){
			return max(dfs(k+1,c1+1,c2,c3,sum+a1[k+1]),dfs(k+1,c1,c2,c3+1,sum+a3[k+1]));
		}
		if(c1<n/2&&c2<n/2&&c3==n/2){
			return max(dfs(k+1,c1,c2+1,c3,sum+a2[k+1]),dfs(k+1,c1+1,c2,c3,sum+a1[k+1]));
		}
	}
}

bool cmp1(int a,int b){
	return a>b;
}


signed main(){

	ios::sync_with_stdio(0),cin.tie(0);

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--){
//		for(int i=1;i<=100005;i++){
//			for(int j=1;j<=3;j++){
//				dp[i][j]=0;
//			}
//		}
//		memset(a1,0,sizeof a1);
//		memset(a2,0,sizeof a2);
//		memset(a3,0,sizeof a3);
//		memset(aa,0,sizeof aa);
		
		bool f2=true,f3=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0) f2=false;
			if(a3[i]!=0) f3=false;
		}
//		int c1=0,c2=0,c3=0;
//		dp[1][1]=a1[1];
//		dp[1][2]=a2[1];
//		dp[1][3]=a3[1];
//		for(int i=2;i<=n;i++){
//			if(c1<n/2){
//				dp[i][1]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
//				c1++;
//			}
//			
//		}
		if(f2==true&&f3==true){
			sort(a1+1,a1+1+n,cmp1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a1[i];
			}
			cout<<sum<<endl;
		}
//		if(f2==false&&f3==true){
//			for(int i=1;i<=n;i++){
//				aa[i]=a1[i];
//			}
//			for(int i=1;i<=n;i++){
//				aa[i+n]=a2[i];
//			}
//			sort(aa+1,aa+1+2*n,cmp2);
//		}
		if(f2==false&&f3==false&&n<=30){
			cout<<dfs(0,0,0,0,0)<<endl;
		}
	}


	return 0;
}
/*
1 4
0 1 0 
0 2 0 
0 1 0 
0 2 0 
*/