#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[200200][4];
long long vis[4];
long long ans=0; 
long long score=0;

void dfs(int p) {
	if(p>n) {
		ans=max(score,ans);
		p--;
		return;
	}
	for(int i=1; i<=3; i++) { 
		if(vis[i]+1<=(n/2)) {
			score+=a[p][i];
			vis[i]++,p++;
			dfs(p);
			vis[i]--,p--;
			score-=a[p][i];
		} else continue;
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int h=1; h<=t; h++) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++)
				cin >> a[i][j];
		}
		dfs(1);

		cout << ans << "\n";
		ans=0;
		score=0;
	}
	return 0;
}




