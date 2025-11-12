#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
struct node{
	int c[3];
	int val;
}dp[N];
vector<pii> v[N];
priority_queue<pii,vector<pii>,greater<pii> > q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			v[i].clear();
			for(int j=0;j<3;j++){
				int x;
				cin>>x;
				v[i].push_back({x,j});
			}
		}
		for(int i=1;i<=n;i++){
			dp[i].val=-INT_MAX;
			dp[i].c[0]=0;
			dp[i].c[1]=0;
			dp[i].c[2]=0;
		}
		for(int i=1;i<=n;i++){
			sort(v[i].begin(),v[i].end());
			reverse(v[i].begin(),v[i].end());
			if(dp[i-1].c[v[i][0].second]+1<=n/2){
				q[v[i][0].second].push({v[i][0].first-v[i][1].first,i});
				dp[i].val=dp[i-1].val+v[i][0].first;
				dp[i].c[0]=dp[i-1].c[0];
				dp[i].c[1]=dp[i-1].c[1];
				dp[i].c[2]=dp[i-1].c[2];
				dp[i].c[v[i][0].second]++;
			}
			else{
				int tmp=q[v[i][0].second].top().second;
				if(v[i][0].first+v[tmp][1].first>v[tmp][0].first+v[i][1].first){
					q[v[i][0].second].pop();
					q[v[i][0].second].push({v[i][0].first-v[i][1].first,i});
					q[v[tmp][1].second].push({v[tmp][1].first-v[tmp][2].first,tmp});
					dp[i].val=dp[i-1].val+v[i][0].first+v[tmp][1].first-v[tmp][0].first;
					dp[i].c[0]=dp[i-1].c[0];
					dp[i].c[1]=dp[i-1].c[1];
					dp[i].c[2]=dp[i-1].c[2];
					dp[i].c[v[tmp][1].second]++;
				}
				else{
					q[v[i][1].second].push({v[i][1].first-v[i][2].first,i});
					dp[i].val=dp[i-1].val+v[i][1].first;
					dp[i].c[0]=dp[i-1].c[0];
					dp[i].c[1]=dp[i-1].c[1];
					dp[i].c[2]=dp[i-1].c[2];
					dp[i].c[v[i][1].second]++;
				}
			}
		}
		for(int i=0;i<3;i++){
			while(!q[i].empty()) q[i].pop();
		}
		cout<<dp[n].val<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}