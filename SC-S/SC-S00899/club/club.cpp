#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 1e5+5;

struct IDX {
	int id1,id2,id3;
}arr[MAXN];
int n;

bool check1() {
	for (int i=1;i<=n;i++) if (arr[i].id2 || arr[i].id3) return 0;
	return 1;
}

bool check2() {
	for (int i=1;i<=n;i++) {if (arr[i].id3) return 0;}
	return 1;
}

bool cmp(IDX a,IDX b) {return a.id1 > b.id1;}
bool cmp1(IDX a,IDX b) {return a.id2 > b.id2;}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>arr[i].id1>>arr[i].id2>>arr[i].id3;
		}
		if (check1()) {
			sort(arr+1,arr+1+n,cmp);
			int ans = 0;
			for (int i=1;i<=n/2;i++){
				ans += arr[i].id1;
			}
			cout<<ans;
		}
		else if (check2()) {
			int ans = 0;
			for (int i=1;i<=n;i++) {
				ans += arr[i].id1;
				arr[i].id2 = arr[i].id2 - arr[i].id1;
			}
			sort(arr+1,arr+1+n,cmp1);
			for (int i=1;i<=n/2;i++) {
				if (arr[i].id2 < 0) continue;
				ans += arr[i].id2;
			}
			cout<<ans;
		}
		return 0;
	}
}