#include<bits/stdc++.h>
using namespace std;
int dp[35][35][35][35],a[100005][4];
struct node{
	int fi,se,cha1,now;
}b[100005];
int cnt[5],n;
int calc(){
	int res=0;
	for(int i=1;i<=n;i++)res+=a[i][b[i].now];
	return res;
}
struct node2{
	int x,y;
};
vector<node2>pr;
bool cmp(node2 x,node2 y){
	return x.y<y.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=30){
			memset(dp,0,sizeof dp);
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n>>1;j++)
					for(int k=0;k<=n>>1;k++)
						for(int l=0;l<=n>>1;l++)
							if(j+k+l<=i){
								if(j>=1)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i][1]);
								if(k>=1)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+a[i][2]);
								if(l>=1)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+a[i][3]);
								ans=max(ans,dp[i][j][k][l]);
							}
							else break;
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				int tmp=0;
				for(int j=1;j<=3;j++)
					if(a[i][j]>tmp){
						tmp=a[i][j];
						b[i].fi=j;
					}
				tmp=1e9;
				int th;
				for(int j=1;j<=3;j++)
					if(a[i][j]<tmp){
						tmp=a[i][j];
						th=j;
					}
				for(int j=1;j<=3;j++)
					if(j!=b[i].fi&&j!=th){
						b[i].se=j;
						break;
					}
				b[i].cha1=a[i][b[i].fi]-a[i][b[i].se];
				b[i].now=b[i].fi;
			}
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++)cnt[b[i].now]++;
			if(max({cnt[1],cnt[2],cnt[3]})<=n/2){
				cout<<calc()<<'\n';
				continue;
			}
			int pos=0;
			for(int i=1;i<=3;i++)if(cnt[i]>n/2)pos=i;
			pr.clear();
			for(int i=1;i<=n;i++)
				if(b[i].now==pos)
					pr.push_back({i,b[i].cha1});
			sort(pr.begin(),pr.end(),cmp);
			for(auto i:pr){
				b[i.x].now=b[i.x].se;
				cnt[pos]--;
				cnt[b[i.x].now]++;
				if(cnt[pos]==n/2)break;
			}
			cout<<calc()<<'\n';
		}
	}
	return 0;
}
//14:59 40pts
//16:01 100pts?
