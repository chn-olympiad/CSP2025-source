#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,inf=1e18;
int n,ans;
int a[N][5];
vector<int> v[5];
priority_queue<int> q;
void clear(){
	ans=0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	while(!q.empty()) q.pop();
}
void solve(){
	cin>>n;
	
	clear();
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=3;++j)
			cin>>a[i][j];
	
	for(int i=1;i<=n;++i){
		int cur=-1,k=0;
		for(int j=1;j<=3;++j)
			if(a[i][j]>cur) cur=a[i][j],k=j;
		v[k].push_back(i);
		ans+=cur;
	}
	
	int k=0;
	for(int i=1;i<=3;++i){
		int sz=v[i].size();
		if(sz > n/2){
			k=i;
			break;
		}
	}
	
	if(k==0){
		cout<<ans<<"\n";
		return;
	}
	
	for(int x:v[k]){
		int cur=inf;
		for(int i=1;i<=3;++i){
			if(i==k) continue;
			cur=min(cur,a[x][k]-a[x][i]);
		}
		q.push(-cur);
	}
	
	int t=v[k].size()-n/2;
	
	while(t>0){
		ans-= - q.top();
		q.pop();
		t--;
	}
	
	cout<<ans<<"\n";
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--) solve();
	
	return 0;
}
