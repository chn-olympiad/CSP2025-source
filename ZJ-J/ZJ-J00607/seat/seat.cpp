#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 10;

int n,m,s;
struct stu{
	int id,pts;
};
stu a[N];

bool cmp (stu x,stu y){
	return x.pts > y.pts;
}
void solve(){
	cin >> n >> m; s = n * m;
	for (int i = 1 ; i <= s ; i++) cin >> a[i].pts,a[i].id = i;
	sort(a + 1,a + s + 1,cmp);
	int mango = 1,ljd = 1;
	bool ff = 1;
	for (int i = 1 ; i <= s ; i++){
		if (a[i].id == 1) break;
		if (ff){
			ljd++;
			if (ljd == n + 1){
				ljd = n; mango++;
				ff = 0;
			}
		}else{
			ljd--;
			if (!ljd){
				ljd = 1; mango++;
				ff = 1;
			}
		}
	}
	cout << mango << ' ' << ljd << endl;
}
signed main(){
	//freopen("seat3.in","r",stdin);
	//freopen("my.txt","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
