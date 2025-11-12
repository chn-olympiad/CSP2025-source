#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[4],t;
struct edge{
	ll id,a1,a2,a3,maxn;
}nu[100005];
struct cmp{
	bool operator()(ll & a,ll & b){
		return a > b;
	}
};
priority_queue<ll,vector<ll>,cmp>q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		int n,ans = 0;
		cin >> n;
		cnt[1] = 0,cnt[2] = 0,cnt[3] = 0;
		for (int i =1;i <= 3;i++) while(!q[i].empty())q[i].pop();
		for (int i = 1;i <= n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if (a >= b && a >= c){
				cnt[1]++;
				ans+=a;
				q[1].push(min(a - b,a - c));
			}
			else if (b >= a && b >= c){
				cnt[2]++;
				ans+=b;
				q[2].push(min(b - a,b - c));
			}
			else if (c >= b && c >= a){
				cnt[3]++;
				ans+=c;
				q[3].push(min(c - a,c - b));
			}
		}
		if (cnt[1] > n / 2){
			while(cnt[1] > n / 2){
				ll head = q[1].top();
				ans -= head;
				q[1].pop();
				cnt[1]--;
			}
		}
		if (cnt[2] > n / 2){
			while(cnt[2] > n / 2){
				ll head = q[2].top();
				ans -= head;
				q[2].pop();
				cnt[2]--;
			}
		}
		if (cnt[3] > n / 2){
			while(cnt[3] > n / 2){
				ll head = q[3].top();
				ans -= head;
				q[3].pop();
				cnt[3]--;
			}
		}
		//cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";
		cout << ans << "\n";
	}
	return 0;
}

