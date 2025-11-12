#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans;
priority_queue<int,vector<int>,greater<int> > q[4];
void solve(int x){
	while(q[x].size()>n/2){
		int p=q[x].top();
		q[x].pop();
		ans-=p;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
		ans=0;
		for(int i=1;i<=n;i++){
			int maxx=-1,pos,mixx=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=maxx){
					pos=j;
					mixx=maxx;
					maxx=a[i][j];
				}
				else if(a[i][j]>mixx) mixx=a[i][j];
			}
			q[pos].push(maxx-mixx);
			ans+=maxx;
		}
		if(q[1].size()>n/2) solve(1);
		else if(q[2].size()>n/2) solve(2);
		else solve(3);
		cout<<ans<<'\n';
	}
	return 0;
}
