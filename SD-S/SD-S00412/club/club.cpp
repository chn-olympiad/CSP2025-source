#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int zhi;
};
bool cmp(node x,node y){
	return x.zhi>y.zhi;
}
int dp[205][205][205];
int a[205],b[205],c[205];
void init(){
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		init();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(n<=2){
			dp[1][0][0]=c[1];
			dp[1][1][0]=a[1];
			dp[1][0][1]=b[1];
			for(int i=2;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						dp[i][j][k]=max(dp[i-1][j][k]+c[i],max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k-1]+b[i]));
					}
				}
			}
			int ans=-0x3f3f3f3f;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					if(i<=n/2&&j<=n/2&&i+j>=n/2) ans=max(ans,dp[n][i][j]);
				}	
			}
			cout<<ans<<endl;
		}
		else{
			node ch[100005];
			memset(ch,0,sizeof(ch));
			for(int i=1;i<=n;i++){
				ch[i]={i,b[i]-a[i]};
			}
			sort(ch+1,ch+n+1,cmp);
			int anss=0;
			for(int i=1;i<=n/2;i++) anss+=b[ch[i].num];
			for(int i=n/2+1;i<=n;i++) anss+=a[ch[i].num];
			cout<<anss<<'\n';
		}
	}
	
	return 0;
}
