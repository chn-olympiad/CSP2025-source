#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 6;
ll T, n;
ll stu[N][4];
ll ans=0;
ll cnt[4];
void dfs(ll d,ll sum){
	if(d>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(d+1,sum+stu[d][i]);
			cnt[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		ans=0;
		for (ll i=1;i<=n;i++)cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
		dfs(1,0);
		cout<<ans<<endl;
	}
}

