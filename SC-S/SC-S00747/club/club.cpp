#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int NM = 1e5;
int A[NM+4][3+4],CV[3+4],K[NM+4],GQ[NM+4];
vector<pair<int,int>> T[3+4];
bool vis[NM+4];
set<int> plk;
int n;
ll ans;
bool cmp(const pair<int,int>& a,const pair<int,int>& b){
	return a.first > b.first;
}
void dfs(const int& id,ll sum){
//	cout<<sum<<'\n';
	if(id > n){
		ans = max(ans,sum);
		return ;
	}
	for(int i = 1;i <= 3;i++){
		if(CV[i] < n/2) CV[i]++,dfs(id+1,sum+A[id][i]),CV[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		plk.clear();
		for(int i = 1;i <= 3;i++) T[i].clear(),CV[i] = 0;
		for(int i = 1;i <= n;i++) vis[i] = 0,K[i] = GQ[i] = 0;
		for(int i = 1;i <= n;i++){
			cin>>A[i][1]>>A[i][2]>>A[i][3];
			T[1].push_back({A[i][1],i});
			T[2].push_back({A[i][2],i});
			T[3].push_back({A[i][3],i});
		}
		if(n <= 12) {dfs(1,0),cout<<ans<<'\n';continue;}
		for(int i = 1;i <= 3;i++) sort(T[i].begin(),T[i].end(),cmp);
		for(int i = 0;i < n and (int)plk.size() < n;i++){
			for(int j = 1;j <= 3;j++){
				if((int)plk.size() >= n) break;
				int id = T[j][i].second;
				if(CV[j] >= n/2) continue;
				if(vis[id]){
					if(K[id] < T[j][i].first and CV[j] < n/2)
						K[id] = T[j][i].first,CV[j]++,CV[GQ[id]]--,GQ[id] = j;
					continue;
				}
				if(CV[j] < n/2) K[id] = T[j][i].first,CV[j]++,GQ[id] = j;
				vis[id] = 1;
				plk.insert(id);
			}
		}
		for(int i = 1;i <= n;i++) ans += K[i];
		cout<<ans<<'\n'; 
	}
	return 0;
}
