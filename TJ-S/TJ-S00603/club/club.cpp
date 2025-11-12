#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
vector<pair<pair<int,int>,int> > a;
bool vis[100005];
int fun(int a,int b,int c){
	if(a>=b&&b>=c)return b;
	if(a>=c&&c>=b)return c;
	if(b>=c&&c>=a)return c;
	if(b>=a&&a>=c)return a;
	if(c>=a&&a>=b)return a;
	if(c>=b&&b>=a)return b;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		ans+=fun(t1,t2,t3);
		a.push_back({{t1-fun(t1,t2,t3),1},i});
		a.push_back({{t2-fun(t1,t2,t3),2},i});
		a.push_back({{t3-fun(t1,t2,t3),3},i});
//		clog<<i<<" "
//			<<t1-fun(t1,t2,t3)<<" "
//			<<t2-fun(t1,t2,t3)<<" "
//			<<t3-fun(t1,t2,t3)<<endl;
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int cnt[5]{0};
	for(auto u:a){
		if(vis[u.second]||cnt[u.first.second]==n/2)
			continue;
		cnt[u.first.second]++;
		vis[u.second]=1;
		ans+=u.first.first;
	}
	cout<<ans<<endl;
}
void clear(){
	ans=0;
	memset(vis,0,sizeof(vis));
	a=vector<pair<pair<int,int>,int> >();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve(),clear();
	return 0;
}

