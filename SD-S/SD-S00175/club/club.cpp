#include <bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
int n;
pair<int,int> a[100010][5];
int cnt[5];
int qaq[100010];

void solve(){
	cin >> n;
	int sum = 0;
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++){
		cin >> a[i][1].first >> a[i][2].first >> a[i][3].first;
		a[i][1].second = 1;
		a[i][2].second = 2;
		a[i][3].second = 3;
		sort(a[i]+1,a[i]+4);
		cnt[a[i][3].second]++;
		sum += a[i][3].first;
	}
	int no = 0;
	for (int i=1;i<=3;i++){
		if(cnt[i]>n/2) no = i;
	}
	int msk = 0;
	for (int i=1;i<=n;i++){
		if(a[i][3].second==no) qaq[++msk] = -a[i][3].first+a[i][2].first;
	}
	if(no==0){
		cout << sum << "\n";
	}
	else{
		sort(qaq+1,qaq+msk+1);
		int C = cnt[no]-n/2;
		for (int i=msk;i>=msk-C+1;i--) sum += qaq[i];
		cout << sum << "\n";
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	FAST;
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}


