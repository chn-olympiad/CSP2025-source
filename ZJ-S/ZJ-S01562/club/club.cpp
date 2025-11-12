#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;
int a[maxn],b[maxn],c[maxn];
long long ans=0;
int an=0,bn=0,cn=0;
long long an1=0,bn1=0,cn1=0;
void dfs(int i){
	if(i>n){
		ans=max(ans,1ll*(an1+bn1+cn1));
	}
	if(an+1<=n/2){
		an++;
		an1+=a[i];
		dfs(i+1);
		an--;
		an1-=a[i];
	}
	if(bn+1<=n/2){
		bn++;
		bn1+=b[i];
		dfs(i+1);
		bn--;
		bn1-=b[i];
	}
	if(cn+1<=n/2){
		cn++;
		cn1+=c[i];
		dfs(i+1);
		cn--;
		cn1-=c[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool flag=true,flag1=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) flag=false;
			if(c[i]!=0) flag1=false;
		}
		if(flag==true&&flag1==true){
			sort(a+1,a+n+1);
			int x;
			if(n%2==0) x=n/2;
			else x=n/2+1;
			for(int i=n;i>x;i--){
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}
		else if(n<=30){
			dfs(0);
			cout<<ans<<'\n';
		}
		else{
			long long dp[n/2][n/2][n/2];
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k+j<=i;k++){
						int q=i-j-k;
						if(q>n/2) continue;
						if(j>0){
							dp[j][k][q]=max(dp[j-1][k][q]+a[i],dp[j][k][q]);
						}
						if(k>0){
							dp[j][k][q]=max(dp[j][k-1][q]+b[i],dp[j][k][q]);
						}
						if(q>0){
							dp[j][k][q]=max(dp[j][k][q-1]+c[i],dp[j][k][q]);
						}
					}
				}
			}
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int k=n-i-j;
					if(k>n/2) continue;
					ans=max(ans,dp[i][j][k]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

