#include <bits/stdc++.h>

using namespace std;

#define int long long 

inline int read(){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	int res=0;
	while(c<='9'&&c>='0'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}

const int N=2e2+3,M=1e2+3;

int a[N][3];
int t1[N];
int dp[N][M][M][M];
int ans=0;
int n;

void dfs(int ord,int cnt1,int cnt2,int cnt3,int sum){
	if(ord>n){
		ans=max(ans,sum);
		return;
	}
	bool ok=(cnt1+cnt2+cnt3<=n);
	if(!ok){
		return;
	}
	if(cnt1<n/2){
		dfs(ord+1,cnt1+1,cnt2,cnt3,sum+a[ord][1]);
	}
	if(cnt2<n/2){
		dfs(ord+1,cnt1,cnt2+1,cnt3,sum+a[ord][2]);
	}
	if(cnt3<n/2){
		dfs(ord+1,cnt1,cnt2,cnt3+1,sum+a[ord][3]);
	}
	return;
}

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		ans=0;
		bool b1=1,b2=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
			if(a[i][2]!=0||a[i][3]!=0){
				b1=0;
			}
			if(a[i][3]!=0){
				b2=0;
			}
		}
		if(b1){
			for(int i=1;i<=n;i++){
				t1[i]=a[i][1];
			}
			sort(t1+1,t1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=t1[i];
			}
			cout<<ans<<'\n';
		}else if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}else{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int cnt1=1;cnt1<=min(i,n/2);cnt1++){
					for(int cnt2=1;cnt2<=min(i,n/2);cnt2++){
						if(cnt1==n/2&&cnt2==n/2){
							dp[i][cnt1][cnt2][i-cnt1-cnt2]=max(dp[i-1][cnt1-1][cnt2][i-cnt1-cnt2]+a[i][1],dp[i-1][cnt1][cnt2-1][i-cnt1-cnt2]+a[i][2]);
							continue;
						}
						dp[i][cnt1][cnt2][i-cnt1-cnt2]=max({dp[i-1][cnt1-1][cnt2][i-cnt1-cnt2]+a[i][1],dp[i-1][cnt1][cnt2-1][i-cnt1-cnt2]+a[i][2],dp[i-1][cnt1][cnt2][i-cnt1-cnt2-1]+a[i][3]});
					}
				}
			}
			int ans=0;
			for(int cnt1=1;cnt1<=n/2;cnt1++){
				for(int cnt2=1;cnt2<=n/2;cnt2++){
					ans=max(ans,dp[n][cnt1][cnt2][n-cnt1-cnt2]);
				}
			}
			cout<<ans<<'\n'; 
			//错代码照样粘上去 
		}
		
	}
	return 0;
}
//绝对是dp+滚动数组优化，只不过我特么写错了 