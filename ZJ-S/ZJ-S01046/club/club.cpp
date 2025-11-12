#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
struct Node{
	int a,b,c;
}st[N];
int dp_case1[105][105][105];
void solve(){
	int n; cin>>n;
	if(n<=200){ // case 1-11
		memset(dp_case1,-0x3f,sizeof dp_case1);
		dp_case1[0][0][0]=0;
		for(int t=1;t<=n;t++){
			int a,b,c;
			cin>>a>>b>>c;
			int now=t&1;
			int lst=now^1;
			int lim_i=min(n/2,t);
			for(int i=lim_i;i>=0;i--){
				int lim_j=min(n/2,t-i);
				for(int j=lim_j;j>=0;j--){
					int lim_k=min(n/2,t-i-j);
					for(int k=lim_k;k>=0;k--){
						if(i)dp_case1[i][j][k]=max(dp_case1[i][j][k],
												   dp_case1[i-1][j][k]+a);
						if(j)dp_case1[i][j][k]=max(dp_case1[i][j][k],
												   dp_case1[i][j-1][k]+b);
						if(k)dp_case1[i][j][k]=max(dp_case1[i][j][k],
												   dp_case1[i][j][k-1]+c);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2)continue;
				ans=max(ans,dp_case1[i][j][k]);
			}
		cout<<ans<<'\n';
		return;
	}
	int maxb=0,maxc=0;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].b>>st[i].c;
		maxb=max(maxb,st[i].b);
		maxc=max(maxc,st[i].c);
	}
	if(!maxb&&!maxc){ // case 12
		sort(st+1,st+n+1,[](const Node&x,const Node&y){
			return x.a>y.a;
		});
		int ans=0;
		for(int i=1;i<=n/2;i++)
			ans+=st[i].a;
		cout<<ans<<'\n';
		return;
	}
	if(!maxc){ // case 13-14
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=st[i].a;
			st[i].b-=st[i].a;
		}
		sort(st+1,st+n+1,[](const Node&x,const Node&y){
			return x.b>y.b;
		});
		for(int i=1;i<=n/2;i++)
			ans+=st[i].b;
		cout<<ans<<'\n';
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}