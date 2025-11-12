#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;

struct node{
	int v1;
	int v2;
	int v3;	
}v[100005];
int t,n;
int a[200005][5];
int dp[200005][5];
int c[5];
bool check(int y,int z){
	if(c[y]+c[z]>n/2){
		return 0;
	}return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int s=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				c[j]=0;
				for(int k=0;k<=2;k++){
					if(check(j,k)){
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
						c[k]++;
					}
				}
			}
		}for(int i=0;i<=2;i++){
			s=max(s,dp[n][i]);
		}cout<<s<<endl;
		//printf("%d\n",s);
	}
	return 0;
}
