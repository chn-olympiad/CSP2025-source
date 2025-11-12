#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
const int N=1e5+5; 
int t,n,cnt[3];
struct node{
	int val,idx;
	bool operator<(const node& other)const{
		return val<other.val;
	}
	
}a[N][3];
bool cmp(node a,node b){
	return a.val<b.val;
}
void dfs(int n,int idx,int &ans,int now){
	//cout<<now<<"\n";
	if(idx>n){ans=max(ans,now);return;}
	for(int i=0;i<3;i++){
		dfs(n,idx+1,ans,now+a[idx][i].val);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fre("club");
	cin>>t;
	while(t--){
		cnt[0]=cnt[1]=cnt[2]=0;
		priority_queue<pair<node,int> ,vector<pair<node,int> >,greater<pair<node,int> > >q[3];
		cin>>n;
		if(n<=10){
			for(int i=1;i<=n;i++)cin>>a[i][0].val>>a[i][1].val>>a[i][2].val;
			int ans=0;
			dfs(n,1,ans,0);
			cout<<ans<<"\n";
			continue;
		}
		int ans=0;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][0].val>>a[i][1].val>>a[i][2].val;
			a[i][0].idx=0;a[i][1].idx=1;a[i][2].idx=2;
			sort(a[i],a[i]+3,cmp);
			if(a[i][1].val!=0)fl=0;
		}
		if(fl){
			for(int i=1;i<=n;i++)ans+=a[i][2].val;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(cnt[a[i][2].idx]==(n>>1)){
				if(cnt[a[i][1].idx]==(n>>1)){
					cnt[a[i][0].idx]++;
					q[1].push({a[i][1],a[i][1].val-a[i][0].val});
					node eg=q[1].top().first;
					q[1].pop();
					int idx=eg.idx;
					q[2].push({a[idx][0],a[idx][0].val});
				}else{
					cnt[a[i][1].idx]++;
					q[0].push({a[i][2],a[i][2].val-a[i][1].val});
					node eg=q[0].top().first;
					q[0].pop();
					int idx=eg.idx;
					int now=a[idx][1].val-a[idx][0].val;
					q[1].push({a[idx][1],now});
				}
			}else{
				cnt[a[i][2].idx]++;
				q[0].push({a[i][2],a[i][2].val-a[i][1].val});
			}
		}
		for(int i=0;i<3;i++)while(!q[i].empty())ans+=q[i].top().first.val,q[i].pop();
		cout<<ans<<"\n";
	}
	return 0;
} 