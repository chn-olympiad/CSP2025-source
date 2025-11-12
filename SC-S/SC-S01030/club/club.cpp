#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,a[N][3],ans;
vector<int>v[3];
struct node{
	int id,t;
	bool operator<(const node B)const{
		return (a[id][t]-max(a[id][(t+1)%3],a[id][(t+2)%3])>
		a[B.id][B.t]-max(a[B.id][(B.t+1)%3],a[B.id][(B.t+2)%3]));
	}
};
priority_queue<node>q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++){
			v[i].clear();
		}
		while(!q.empty())q.pop();
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				v[0].push_back(i);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				v[1].push_back(i);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
				v[2].push_back(i);
			}
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		int id=3;
		for(int i=0;i<3;i++){
			if(v[i].size()>n/2)id=i;
		}
		if(id==3){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0;i<v[id].size();i++){
			q.push({v[id][i],id});
		}
		int m=v[id].size()-(n/2);
		while(m){
			node x=q.top();q.pop();m--;
			ans-=a[x.id][x.t]-max(a[x.id][(x.t+1)%3],a[x.id][(x.t+2)%3]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
15min。
100pts。
*/