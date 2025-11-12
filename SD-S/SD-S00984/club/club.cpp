#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ve vector
#define pb push_back
#define pii pair<int,int> 
#define p_q priority_queue
#define mk make_pair
#define fi first
#define se second
namespace cute_fzj_kuai_ruarua{
	int n,a[100005][4],id[100005],vall[4];
	p_q<pii,ve<pii >,greater<pii > >q[4];
	int val(int te){
		if((int)q[te].size()<n/2) return 0;
		int now_=q[te].top().fi;
		return now_;
	}
	void insert_(int te){
		if((int)q[te].size()<n/2) return ;
		int mx_=q[te].top().fi,id=q[te].top().se;
		q[te].pop();
		for(int i=1;i<=3;i++){
			if(a[id][te]-a[id][i]==mx_){
				int nxtval;
				if(i==1) nxtval=a[id][i]-max(a[id][2],a[id][3]);
				if(i==2) nxtval=a[id][i]-max(a[id][1],a[id][3]);
				if(i==3) nxtval=a[id][i]-max(a[id][2],a[id][1]);
				q[i].push(mk(nxtval,id));
				return ;
			}
		}
		return ;
	}
	void solve(){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int sum=0;
		for(int i=1;i<=3;i++){
			vall[i]=0;
			while(q[i].size()) q[i].pop();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) vall[j]=a[i][j]-val(j);
			int mx_=max(vall[1],max(vall[2],vall[3]));
			sum+=mx_;
			if(mx_==vall[1]){
				insert_(1);
				q[1].push(mk(a[i][1]-max(a[i][2],a[i][3]),i));
				continue;
			}
			if(mx_==vall[2]){
				insert_(2);
				q[2].push(mk(a[i][2]-max(a[i][1],a[i][3]),i));
				continue;
			}
			if(mx_==vall[3]){
				insert_(3);
				q[3].push(mk(a[i][3]-max(a[i][2],a[i][1]),i));
				continue;
			}
		}
		cout<<sum<<endl;
	}
	void main(){
		int T;
		cin>>T;
		while(T--) solve();
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}
// T1 反悔贪心是不是有点过于困难了 
