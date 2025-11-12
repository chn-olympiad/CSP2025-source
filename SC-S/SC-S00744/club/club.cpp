#include<bits/stdc++.h>
using namespace std;
int n,a[3];
inline bool cmp(int x,int y){
	return a[x]>a[y];
}
inline void solve(){
	cin>>n;
	int mp=n/2,ans=0;
	priority_queue<int,vector<int>,greater<int> >q[3];
	for(int i=1;i<=n;i++){
		int id[3];
		cin>>a[0]>>a[1]>>a[2],id[0]=0,id[1]=1,id[2]=2;
		sort(id,id+3,cmp);
		if(q[id[0]].size()>=mp){//x-y     q[0]-q[1] 
			if(q[id[0]].top()<a[id[0]]-a[id[1]])
				ans+=a[id[0]]-q[id[0]].top(),q[id[0]].pop(),q[id[0]].push(a[id[0]]-a[id[1]]); 
			else ans+=a[id[1]];
		}
		else ans+=a[id[0]],q[id[0]].push(a[id[0]]-a[id[1]]);
	}
	cout<<ans<<"\n";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
} 
//好题啊 