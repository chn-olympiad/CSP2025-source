#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
struct pes{
	int a, b, c;
	bool vis;
}ps[100005];

bool cmp(struct pes a, struct pes b){
	int ma = max(max(a.a-a.b-a.c, a.b-a.a-a.c), a.c-a.a-a.b);
	int mb = max(max(b.a-b.b-b.c, b.b-b.a-b.c), b.c-b.b-b.a);
	if(ma > mb){
		return 1;
	}else if(mb > ma){
		return 0;
	}else{
		ma = min(min(a.a-a.b-a.c, a.b-a.a-a.c), a.c-a.a-a.b);
		mb = min(min(b.a-b.b-b.c, b.b-b.a-b.c), b.c-b.b-b.a);
		if(ma > mb){
			return 1;
		}else{
			return 0;
		}
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> ps[i].a >> ps[i].b >> ps[i].c;
		}
		sort(ps+1, ps+1+n, cmp);
		int ans = 0, a = 0, b = 0, c = 0;
		for(int i = 1;i <= n;i++){
			int mx = -1, chs = -1;
			cout << ps[i].a << ' ' << ps[i].b << ' ' << ps[i].c << endl;
			if(a < n/2 && ps[i].a > mx){
				mx = ps[i].a;
				chs = 1;
			}
			if(b < n/2 && ps[i].b > mx){
				mx = ps[i].b;
				chs = 2;
			}
			if(c < n/2 && ps[i].c > mx){
				mx = ps[i].c;
				chs = 3;
			}
			if(chs == 1){
				a++;
			}else if(chs == 2){
				b++;
			}else{
				c++;
			}
			ans += mx;
			//cout << mx << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
