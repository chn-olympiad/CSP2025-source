#include <bits/stdc++.h>
using namespace std;
long long a[100005][4];
int b[4];
long long ans=0,ans1=0;
int n;
void dfs(int m) {
	if (m>n) {
		ans=max(ans,ans1);
		return;
	}
	for (int i=1;i<=3;i++) {
		if (b[i]+1>n/2) continue;
		b[i]++;
		ans1+=a[m][i];
		dfs(m+1);
		ans1-=a[m][i];
		b[i]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int i=1;i<=t;i++) {
		cin >> n;
		for (int j=1;j<=n;j++) {
			cin >> a[j][1]>>a[j][2]>>a[j][3];
		}
		ans=0;
		ans1=0;
		b[1]=b[2]=b[3]=0;
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
}
