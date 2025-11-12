#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int N=1e5+10;
priority_queue<int>q;
int cnt[4];
int a[N][4];
int w[N],nd[N],fi[N];
bool cmp(pi a,pi b){
	if(a.first!=b.first)return a.first>b.first;
	return a.second>b.second;
}
void work(){
	while(!q.empty())q.pop();
	memset(cnt,0,sizeof cnt);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<pi>op;
		op.push_back({a[i][1],1});
		op.push_back({a[i][2],2});
		op.push_back({a[i][3],3});
		sort(op.begin(),op.end(),cmp);
		cnt[op[0].second]++;
		ans+=op[0].first;
		w[i]=op[0].second;
		nd[i]=op[1].first;
		fi[i]=op[0].first;
	}
	int tp=0;
	if(cnt[1]>n/2)tp=1;
	else if(cnt[2]>n/2)tp=2;
	else if(cnt[3]>n/2)tp=3;
	else{
		cout<<ans<<"\n";return;
	}
//	cout<<tp<<" "<<cnt[tp]<<"  db\n";
	for(int i=1;i<=n;i++){
		if(w[i]==tp)q.push((nd[i]-fi[i]));
	}
	while(cnt[tp]>n/2){
		ans+=q.top();
		q.pop();
		cnt[tp]--;
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}