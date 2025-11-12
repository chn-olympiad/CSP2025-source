#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,N2=250;
int n,maxx;
struct NODE {
	int a,b,c;	
}a[N];
void dfs1(int x,int y,int z,int ans) {
	if(x>n/2||y>n/2||z>n/2) return;
	if(x+y+z==n) {
		maxx=max(maxx,ans);
		return;
	}
	dfs1(x+1,y,z,ans+a[x+y+z].a);
	dfs1(x,y+1,z,ans+a[x+y+z].b);
	dfs1(x,y,z+1,ans+a[x+y+z].c);
	return; 
}
bool cmp(NODE x,NODE y) {
	return x.a<y.a;
}
int dp[N2][N2][N2][N2];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		maxx=0;
		cin>>n;
		int subf=1;
		for(int i=0;i<n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0&&a[i].c!=0) subf=0;
		}
		if(n<=20) {
			dfs1(0,0,0,0);
			cout<<maxx<<endl;	
		} else if(subf==1) {
			sort(a,a+n,cmp);
			int ans=0;
			for(int i=0;i<n/2;i++) ans+=a[i].a;
			cout<<ans<<endl;
		} else {
			for(int t=0;t<=n;t++) {
				for(int i=0;i<=n/2;i++) {
					for(int j=0;j<=n/2;j++) {
						int k=t-i-j;
						if(k>n/2) continue;
						dp[t+1][i+1][j][k]=max(dp[t+1][i+1][j][k],dp[t][i][j][k]+a[t].a);
						dp[t+1][i][j+1][k]=max(dp[t+1][i][j+1][k],dp[t][i][j][k]+a[t].b);
						dp[t+1][i][j][k+1]=max(dp[t+1][i][j][k+1],dp[t][i][j][k]+a[t].c);
					}
				}
			}
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++) {
					int k=n-i-j;
					maxx=max(maxx,dp[n][i][j][k]);
				}
			cout<<maxx<<endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
