#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	pair<int,int> p[4];
	int t;
}a[100005];
int n;
int qwer1fsdd;
int ans;
priority_queue<pair<int,int> >q[4];
int tmp;
void init(int k){
	a[k].t=3;
	a[k].p[0].first=-2e18;
	cin >> a[k].p[1].first >> a[k].p[2].first >> a[k].p[3].first;
	a[k].p[1].second=1; a[k].p[2].second=2; a[k].p[3].second=3;
	sort(a[k].p+1,a[k].p+4);
}
void ps(int k){
	int hlc=a[k].t;
	q[a[k].p[hlc].second].push({a[k].p[hlc-1].first-a[k].p[hlc].first,k});
	ans+=a[k].p[hlc].first;
//	cout << ans << " " << a[k].p[hlc].first << "\n";
	a[k].t--;
	if(q[a[k].p[hlc].second].size()>n/2){
		pair<int,int>d=q[a[k].p[hlc].second].top();
		q[a[k].p[hlc].second].pop();
		ans-=a[d.second].p[a[d.second].t+1].first;
//		cout << ans << " " << d.first << "\n";
		ps(d.second);
	}
}
signed main(){
//	freopen("csps/down/club/club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> qwer1fsdd;
	while(qwer1fsdd--){
		cin >> n;
		ans=0;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		for(int i=1;i<=n;i++)init(i);
		for(int i=1;i<=n;i++)ps(i);
		cout << ans << "\n";
	}
	return 0;
}
