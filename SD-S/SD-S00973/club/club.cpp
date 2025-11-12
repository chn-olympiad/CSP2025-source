#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
const int N=1e5+10;
const int M=1e3+10;
int a[N][4];
int g[N][4];  //把i放j里数的个数 
int dp[N][4];  //把i放j里可以获得的最大满意度 
int vis[4];
long long sum=0;
long long ans=-1e17;
void dfs(int step){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]+1>(n/2)){
			continue;
		} 
		sum+=a[step][i];
		vis[i]++;
		dfs(step+1);
		sum-=a[step][i];
		vis[i]--;
	}
}
int b[N];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1e17;
		sum=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j>1&&a[i][j]!=0) flag=false;
			} 
		} 
		if(flag==true){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
			cout<<sum<<endl;
			continue;
		}
//		dp[1][1]=a[1][1];
//		dp[1][2]=a[1][2];
//		dp[1][3]=a[1][3];
//		g[1][1]=1;
//		g[1][2]=1;
//		g[1][3]=1; 
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				
//			}
//		}
		for(int i=1;i<=3;i++){
			sum+=a[1][i];
			vis[i]++;
			dfs(2); 
			sum-=a[1][i];
			vis[i]--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//3 1 2 4
//4 3 1 2
//2 3 1 4

//1 2 3 4
//3 4 1 2
//1 2 3 4

//dp[1][1]=0;
//dp[1][3]=0;
//dp[3][2]=2;
//dp[2][1]=0
