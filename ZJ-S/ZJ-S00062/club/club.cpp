#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e5+10;
int n,cnt[10];
struct Node{
	vector<pii>v;
	bool operator<(const Node x)const{
		return v[2].first>x.v[2].first;
	}
}a[N];
void init(){
	cin>>n;
	for(int i=1;i<=n;++i) {
		a[i].v.clear();
		for(int j=0;j<3;++j){
			int q;
			cin>>q;
			a[i].v.push_back({q,j});
		}
		sort(a[i].v.begin(),a[i].v.end());
	}
	for(int i=0;i<3;++i) cnt[i]=0;
}

void solve(){
	long long ans=0;
	for(int i=1;i<=n;++i){
		cnt[a[i].v[2].second]++;
		ans+=a[i].v[2].first;
	}
	int x=-1;
	if(cnt[0]>n/2)x=0;
	else if(cnt[1]>n/2) x=1;
	else x=2;
	if(x!=-1){
		vector<long long>chg;
		for(int i=1;i<=n;++i){
			if(a[i].v[2].second==x) chg.push_back(a[i].v[2].first-a[i].v[1].first);
		}
		sort(chg.begin(),chg.end());
		for(int i=0;i<cnt[x]-n/2;++i) ans-=chg[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;cin>>t;
	while(t--){
		init();
		solve();
	}
	return 0;
}
/*
fc club5.ans club.out
*/
