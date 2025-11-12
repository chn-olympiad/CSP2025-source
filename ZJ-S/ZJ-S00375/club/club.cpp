#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int a[N][4];
int cnt[4];
bool used[N];
struct node {
	int id;
	int val;
	bool operator<(const node &a)const {
		return val>a.val;
	}
};
priority_queue<node> q[3];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	while(t--) {
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
		memset(cnt,0,sizeof(cnt));
		memset(used,0,sizeof(used));
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
			}
		}
		int res=0;
		for(int i=1; i<=n; i++) {
			int j;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				j=1;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				j=2;
			}
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]) {
				j=3;
			}
			cnt[j]++;
			res+=a[i][j];
			for(int k=1; k<=3; k++) {
				if(k!=j) {
					q[j].push({i,a[i][j]-a[i][k]});
				}
			}
		}
		int cnt_max;
		if(cnt[1]>cnt[2]&&cnt[1]>cnt[3]) cnt_max=1;
		if(cnt[2]>cnt[1]&&cnt[2]>cnt[3]) cnt_max=2;
		if(cnt[3]>cnt[2]&&cnt[3]>cnt[1]) cnt_max=3;
		while(cnt[cnt_max]>n/2){			
			int id=q[cnt_max].top().id;
			int val=q[cnt_max].top().val;
			q[cnt_max].pop();
			if(!used[id]){
				used[id]=true;
				res-=val;
				cnt[cnt_max]--;
			}
		}
		cout<<res<<endl;
	}
}
