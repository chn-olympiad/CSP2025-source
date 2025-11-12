#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}s[100010];
//int f[100010];
//int r[100010];
long long dp[80][80][80][80];
long long dp1[350][350][350];
bool cmp(node s1,node s2){
	if (s1.a!=s2.a){
		return s1.a>s2.a;
	}
	return s1.b>s2.b;
}
//bool cmp2(node s1,node s2){
//	if (s1.b!=s2.b){
//		return s1.b>s2.b;
//	}
//	return s1.a>s2.a;
//}
//bool cmp1(int s1,int s2){
//	return s1>s2;
//}
long long maxx;
int n;
bool fg,kl;
//void dfs(int x,int ol,int op,int ok,long long ans){
//	if (x==n+1){
//		if (ol<=n/2 && op<=n/2 && ok<=n/2){
//			maxx=max(maxx,ans);
//		}
//		return ;
//	}
//	dfs(x+1,ol+1,op,ok,ans+s[x].a);
//	dfs(x+1,ol,op+1,ok,ans+s[x].b);
//	dfs(x+1,ol,op,ok+1,ans+s[x].c);
//}
long long sum,ans;
int cnt,df,ik;
int as,ad,af;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		cin >> n;
		fg=0;
		sum=0;
		maxx=0;
		kl=0;
		cnt=0;
		df=0;
		ik=0;
		ans=0;
		for (int i=1;i<=n;i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			if (s[i].b!=0 || s[i].c!=0){
				fg=1;
			}
			if (s[i].c!=0){
				kl=1;
			}
		}
		if (fg==0){
			sort(s+1,s+n+1,cmp);
			for (int i=1;i<=n/2;i++){
				sum+=s[i].a;
			}
			cout << sum << endl;
			continue;
		}
//		if (n<=20){
//			dfs(1,0,0,0,0);
//			cout << maxx << endl;
//			continue;
//		}
		as=0,ad=0,af=0;
		sum=0;
		for (int i=1;i<=n;i++){
			if (s[i].a==max(s[i].a,max(s[i].b,s[i].c))){
				as++;
				sum+=s[i].a;
			}
			else if (s[i].b==max(s[i].a,max(s[i].b,s[i].c))){
				ad++;
				sum+=s[i].b;
			}
			else{
				af++;
				sum+=s[i].c;
			}
		}
		if (as<=n/2 && ad<=n/2 && af<=n/2){
			cout << sum << endl;
			continue;
		}
//		sum=0;
//		if (kl==0){
//			sort(s+1,s+n+1,cmp);
//			for (int i=1;i<=n;i++){
//				if (s[i].a>=s[i].b && ik<n/2){
//					sum+=s[i].a;
//					ik++;
//				}
//				else if (s[i].a<s[i].b && df>n/2){
//					sum+=s[i].a;
//					ik++;
//				}
//				else{
//					f[++cnt]=s[i].b;
//					df++;
//				}
//			} 
//			sort(f+1,f+cnt+1,cmp1);
//			for (int i=1;i<=cnt;i++){
//				sum+=f[i];
//			}
//			ik=0;
//			df=0;
//			cnt=0;
//			ans=0;
//			sort(s+1,s+n+1,cmp2);
//			for (int i=1;i<=n;i++){
//				if (s[i].b>=s[i].a && ik<n/2){
//					ans+=s[i].b;
//					ik++;
//				}
//				else if (s[i].b<s[i].a && df>=n/2){
//					ans+=s[i].b;
//					ik++;
//				}
//				else{
//					r[++cnt]=s[i].a;
//					df++;
//				}
//			} 
//			sort(r+1,r+cnt+1,cmp1);
//			for (int i=1;i<=cnt;i++){
//				ans+=r[i];
//			}
//			cout << max(sum,ans) << endl;
//			continue;
//		}
		if (n<=75){
			dp[0][0][0][0]=0;
			for (int i=1;i<=n;i++){
				for (int j=0;j<=n;j++){
					for (int k=0;k<=n;k++){
						for (int l=0;l<=n;l++){
							if (j+k+l<=i){
								dp[i][j][k][l]=dp[i-1][j][k][l];
								if (j-1>=0){
									dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+s[i].a);
								}
								if (k-1>=0){
									dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+s[i].b);
								}
								if (l-1>=0){
									dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+s[i].c);
								}
							}
						}
					}
				}
			}
//			for (int i=1;i<=n;i++){
//				for (int j=0;j<=n;j++){
//					for (int k=0;k<=n;k++){
//						for (int l=0;l<=n;l++){
//							cout << dp[i][j][k][l] << " "; 
//						}
//					}
//				}
//			}
			maxx=0;
			for (int i=0;i<=n;i++){
				for (int j=0;j<=n;j++){
					for (int k=0;k<=n;k++){
						if (i+j+k<=n && i<=n/2 && j<=n/2 && k<=n/2){
							maxx=max(maxx,dp[n][i][j][k]);
						}
					}
				}
			}
			cout << maxx << endl;
			continue;
		}
		else if (kl==0){
			dp1[0][0][0]=0;
			for (int i=1;i<=n;i++){
				for (int j=0;j<=n;j++){
					for (int k=0;k<=n;k++){
						if (j+k<=i){
							dp1[i][j][k]=dp1[i-1][j][k];
							if (j-1>=0){
								dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j-1][k]+s[i].a);
							}
							if (k-1>=0){
								dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k-1]+s[i].b);
							}
						}
					}
				}
			}
//			for (int i=1;i<=n;i++){
//				for (int j=0;j<=n;j++){
//					for (int k=0;k<=n;k++){
//						for (int l=0;l<=n;l++){
//							cout << dp[i][j][k][l] << " "; 
//						}
//					}
//				}
//			}
			maxx=0;
			for (int i=0;i<=n;i++){
				for (int j=0;j<=n;j++){
					if (i+j<=n && i<=n/2 && j<=n/2){
						maxx=max(maxx,dp1[n][i][j]);
					}
				}
			}
			cout << maxx << endl;
			continue;
		}
	}
	return 0;
}
