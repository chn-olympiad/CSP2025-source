#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,t[N][4],k,len;
ll ans;
bool vis[N];
struct node{
	int t,id;
	bool operator<(const node& w)const{
		return this->t>w.t;
	}
}a[N][4];
priority_queue<node>q[4];
priority_queue<int,vector<int>,greater<int> >q2;
vector<node>vec;
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1].t>>a[i][2].t>>a[i][3].t;
		a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		sort(a[i]+1,a[i]+4);
	}
	vec.clear();
	while(q2.size()) q2.pop();
	len=k=0;
	for(int i=1;i<=n;i++) q[a[i][1].id].push({a[i][1].t,i});
	for(int i=1;i<=3;i++){
		if(q[i].size()>n/2){
			len=q[i].size();
			while(q[i].size()){
				node u=q[i].top();
				q[i].pop();
				vec.push_back(u);
				ans+=u.t;
			}
			k=i;
		}else{
			while(q[i].size()){
				node u=q[i].top();
				q[i].pop();
				ans+=u.t;
			}
		}
	}
	for(auto i:vec){
		int u=i.t,p=i.id;
		q2.push(u-a[p][2].t);
	}
	for(int i=1;i<=len-n/2;i++){
		if(q2.empty()) break;
		ans-=q2.top();
		q2.pop();
	}
	cout<<ans<<'\n';
	return;
}
int main(){
//	system("fc club.out club2.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
	cin>>_;
	while(_--) solve();
	return 0;
}
