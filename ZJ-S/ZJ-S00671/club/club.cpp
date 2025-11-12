#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 10;

int n,mx,mxid;
struct node{
	int x,y,z,d;
};
node a[N];

bool cmp (node x,node y){
	if (x.d != mxid) return 0;
	else if (y.d != mxid) return 1;
	else{
		if (mxid == 1) return x.x - max(x.y,x.z) < y.x - max(y.y,y.z);
		else if (mxid == 2) return x.y - max(x.x,x.z) < y.y - max(y.x,y.z);
		else return x.z - max(x.x,x.y) < y.z - max(y.x,y.y);
	}
}
void solve(){
	cin >> n; mx = n / 2;
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].x >= max(a[i].y,a[i].z)) a[i].d = 1,cnt1++;
		else if (a[i].y >= max(a[i].x,a[i].z)) a[i].d = 2,cnt2++;
		else a[i].d = 3,cnt3++;
	}
	int mxcnt = 0;
	if (cnt1 >= max(cnt2,cnt3)) mxid = 1,mxcnt = cnt1;
	else if (cnt2 >= max(cnt1,cnt3)) mxid = 2,mxcnt = cnt2;
	else mxid = 3,mxcnt = cnt3;
	sort(a + 1,a + n + 1,cmp);
	/*
	cout << "!!! " << mxid << endl;
	for (int i = 1 ; i <= n ; i++) cout << a[i].d << ' ';
	cout << endl;
	*/
	for (int i = 1 ; i <= mxcnt - mx ; i++){
		if (mxid == 1){
			if (a[i].y >= a[i].z) a[i].d = 2;
			else a[i].d = 3;
		}else if (mxid == 2){
			if (a[i].x >= a[i].z) a[i].d = 1;
			else a[i].d = 3;
 		}else{
 			if (a[i].x >= a[i].y) a[i].d = 1;
 			else a[i].d = 2;
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= n ; i++){
		if (a[i].d == 1) ans += a[i].x;
		else if (a[i].d == 2) ans += a[i].y;
		else ans += a[i].z;
	}
	cout << ans << endl;
}
signed main(){
	//freopen("club5.in","r",stdin);
	//freopen("my.txt","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> T;
	while (T--) solve();
	return 0;
}
