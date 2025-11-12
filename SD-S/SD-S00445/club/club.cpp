#include<bits/stdc++.h>
#define N 100005
#define pi pair<int,int>
#define int long long
using namespace std;
int T,n,a[N][4],ans;
priority_queue<int>q[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j)cin>>a[i][j];
		}
		for(int i=1;i<=3;++i)while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;++i){
			int x=0;
			for(int j=1;j<=3;++j)if(a[i][j]>=a[i][x])x=j;
			int smax=0;
			for(int j=1;j<=3;++j){
				if(j!=x)smax=max(smax,a[i][j]);
			}
			q[x].push(smax-a[i][x]);ans+=a[i][x];
		}
		for(int i=1;i<=3;++i){
			while(q[i].size()>n/2)ans+=q[i].top(),q[i].pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}

