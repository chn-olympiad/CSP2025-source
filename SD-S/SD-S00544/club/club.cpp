#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e2+1e1;
int t,n,a[N][5];
int dp[N][N][N];
bool fa;
int as[N],ans,tot;

int qread(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	t=qread();
	while(t--){
		n=qread();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				for(int k=0;k<=n;++k)
					for(int l=0;l<=n;++l)
						dp[j][k][l]=0;
		fa=1;
		for(int i=1;i<=n;++i){
			a[i][0]=qread(),a[i][1]=qread(),a[i][2]=qread();
			if(a[i][1]||a[i][2]) fa=0;
		}
		if(fa){
			tot=0;
			for(int i=1;i<=n;++i)
				as[i]=a[i][0];
			sort(as+1,as+1+n);
			for(int i=n;i>(n>>1);--i)
				tot+=as[i];
			cout<<tot<<'\n';
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=(n>>1);j>=0;--j){
				for(int k=(n>>1);k>=0;--k){
					for(int l=(n>>1);l>=0;--l){
						if(j)
							dp[j][k][l]=max(dp[j][k][l],
								dp[j-1][k][l]+a[i][0]);
						if(k)
							dp[j][k][l]=max(dp[j][k][l],
								dp[j][k-1][l]+a[i][1]);
						if(l)
							dp[j][k][l]=max(dp[j][k][l],
								dp[j][k][l-1]+a[i][2]);
					}
				}
			}
		}
		ans=0;
		for(int j=0;j<=(n>>1);++j)
			for(int k=0;k<=(n>>1);++k)
				for(int l=0;l<=(n>>1);++l)
					ans=max(ans,dp[j][k][l]);
		cout<<ans<<'\n';
	}
	return 0;
}
