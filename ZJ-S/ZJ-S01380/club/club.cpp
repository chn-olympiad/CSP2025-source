#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n;
int a[N][5];
int cnt[5];
queue<pair<int,int>>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			vector<pair<int,int>>v;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				v.push_back({a[i][j],j});
			}
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			if(v[0].first>v[1].first){
				cnt[v[0].second]++;
			}else if(v[0].first==v[1].first){
				q.push({v[0].second,v[1].second});
			}
		}
		while(!q.empty()){
			int l=q.front().first;
			int r=q.front().second;
			q.pop();
			if(cnt[l]>=n/2){
				cnt[r]++;
			}else{
				cnt[l]++;
			}
		}
		//cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			ll ans=0;
			for(int i=1;i<=n;i++){
				ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<'\n';
			continue;
		}
		int p=0;
		for(int j=1;j<=3;j++){
			if(cnt[j]>n/2){
				p=j;
				break;
			}
		}
		int k=cnt[p]-n/2;
		int x=0,y=0;
		if(p==1){
			x=2;
			y=3;
		}
		if(p==2){
			x=1;
			y=3;
		}
		if(p==3){
			x=1;
			y=2;
		}
		ll ans=0;
		priority_queue<int,vector<int>,greater<int>>pq;
		for(int i=1;i<=n;i++){
			if(a[i][p]>a[i][x]&&a[i][p]>a[i][y]){
				pq.push(min(a[i][p]-a[i][x],a[i][p]-a[i][y]));
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		while(k--){
			ans-=pq.top();
			pq.pop();
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}