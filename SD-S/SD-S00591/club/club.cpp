#include<bits/stdc++.h>
#define int long long
#define mp make_pair 
#define fi first
#define se second
#define fr front
using namespace std;

int t,n,a[100005][4],cnt[4];

struct choises{
	int val,id;
	friend bool operator<(choises a,choises b){
		return a.val>b.val;
	}
}p[100005][4];

priority_queue<int,vector<int>,greater<int> > q[4];

void solve(){
	int ans=0;
	cnt[1]=0;cnt[2]=0;cnt[3]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			p[i][j].val=a[i][j];
			p[i][j].id=j;
		}
		sort(p[i]+1,p[i]+4);
	}
	for(int i=1;i<=n;i++){
		int now=p[i][1].val-p[i][2].val;
		int id=p[i][1].id;
		//cout<<now<<"\n";
		if(cnt[id]<n/2){
			cnt[id]++;ans+=p[i][1].val;
			q[id].push(now);continue;
		}
		int num=q[id].top();
		//cout<<num<<" "<<now<<"\n";
		if(num<now){
			q[id].pop();ans=ans-num+p[i][1].val;
			q[id].push(now);
		}
		else ans+=p[i][2].val;
	}
	cout<<ans<<"\n";
} 

signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		solve();
		for(int i=1;i<=3;i++){
			while(!q[i].empty())q[i].pop();
		}
	}
}
