#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n;
pair<int,int> a[MAXN][10];
void solve(){
	cin >>n;
	int ans=0;
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= 3;j ++){
			cin >>a[i][j].first;
			a[i][j].second=j;	
		}
		sort(a[i]+1,a[i]+4,greater<pair<int,int> >());
		ans+=a[i][1].first;
	}
	vector<int> cnt(4,0);
	for (int i = 1;i <= n;i ++) cnt[a[i][1].second]++;
	int mx=0,id;
	for (int i = 1;i <= 3;i ++){
		if (cnt[i]>mx){
			mx=cnt[i];
			id=i;	
		}
	}
	if (mx<=n/2){
//		cout <<1;
		cout <<ans<<'\n';
		return;	
	}
	vector<int> ls;
	for (int i = 1;i <= n;i ++){
		if (a[i][1].second!=id) continue;
		ls.push_back(-a[i][1].first+a[i][2].first);
	}
//	for (int i = 0;i < ls.size();i ++) cout <<ls[i]<<' ';
//	cout <<'\n';
	sort(ls.begin(),ls.end(),greater<int>());
	for (int i = 0;i < ls.size();i ++){
		if (mx<=n/2) break;
		ans+=ls[i];
		--mx;
	}
	cout <<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("T1.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >>T;
	while (T--) solve();
	return 0;
}
