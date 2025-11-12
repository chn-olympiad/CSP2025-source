#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int t;
int n,ans,op;
int a[N][5],dp[N][5],tmp[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int f=1;
		ans=0,op=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) f=0;
			tmp[i]=a[i][1];
		}
		if(f) op=2;
		if(op==2){
			sort(tmp+1,tmp+n+1,cmp); 
			for(int i=1;i<=n/2;i++){
				ans+=tmp[i];
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i][1];
				dp[i][2]=max(dp[i-1][1],dp[i-1][3])+a[i][2];
				dp[i][3]=max(dp[i-1][1],dp[i-1][2])+a[i][3];
			}
			cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
