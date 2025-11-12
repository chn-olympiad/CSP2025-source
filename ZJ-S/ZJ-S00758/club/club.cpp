#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int d[N], a[N][5], maxt[N];
int ans;
void solve(){
	int n, cnt1, cnt2, cnt3;
	cnt1 = cnt2 = cnt3 = ans = 0;
	memset(a, 0, sizeof(a));
	cin>>n;
	int k = n/2;
	for(int i = 1; i <= n; i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans += max(max(a[i][1], a[i][2]), a[i][3]); 
		if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) cnt1++, maxt[i] = 1;
		if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) cnt2++, maxt[i] = 2;
		if(a[i][3] > a[i][2] && a[i][3] > a[i][1]) cnt3++, maxt[i] = 3;
		d[i] = 2e4+500;
	}
	int p = -1;
	if(cnt1 > k) p = 1;
	if(cnt2 > k) p = 2;
	if(cnt3 > k) p = 3;
	if(p == -1){
		cout<<ans<<"\n";
		return ;
	}
	if(p == 1){
		for(int i = 1; i <= n; i++)
			if(maxt[i] == 1)
				d[i] = min(a[i][1]-a[i][2], a[i][1]-a[i][3]);
		sort(d+1, d+1+n);
		for(int i = 1; i <= cnt1-k; i++) ans -= d[i];
		cout<<ans<<"\n";
		return ;
	}
	if(p == 2){
		for(int i = 1; i <= n; i++)
			if(maxt[i] == 2)
				d[i] = min(a[i][2]-a[i][1], a[i][2]-a[i][3]);
		sort(d+1, d+1+n);
		for(int i = 1; i <= cnt2-k; i++) ans -= d[i];
		cout<<ans<<"\n";
		return ;
	}
	if(p == 3){
		for(int i = 1; i <= n; i++)
			if(maxt[i] == 3)
				d[i] = min(a[i][3]-a[i][1], a[i][3]-a[i][2]);
		sort(d+1, d+1+n);
		for(int i = 1; i <= cnt3-k; i++) ans -= d[i];
		cout<<ans<<"\n";
		return ;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out ", "w", stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}

