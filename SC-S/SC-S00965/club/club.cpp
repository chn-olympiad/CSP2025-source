#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1);
int T;
int n, m, k, ans;
int cnt[5];
struct edge{
	int a, b, c;
	int mx;
	int mxid;
}e[maxn];
int t[maxn][5];
bool cmp(edge x, edge y){
	return x.mx > y.mx;
}
void init(int n){
	for(int i = 1;i <= n;i ++){
		e[i].a = e[i].b = e[i].c = 0;
		e[i].mx = e[i].mxid = 0;
	}cnt[1] = cnt[2] = cnt[3] = 0;
	ans = 0;
	return;
}
void query(int u, int cnta, int cntb, int cntc, int res){
//	cout << res << " " << cnta << " " << cntb << " " << cntc << " " << u << endl;
	if(u > n){
		ans = max(ans, res);
		return;
	}
	if(cnta < (n / 2)) query(u + 1, cnta + 1, cntb, cntc, res + t[u][1]);
	if(cntb < (n / 2)) query(u + 1, cnta, cntb + 1, cntc, res + t[u][2]);
	if(cntc < (n / 2)) query(u + 1, cnta, cntb, cntc + 1, res + t[u][3]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T --){
		cin >> n;
		init(n);
		for(int i = 1;i <= n;i ++){
			cin >> e[i].a >> e[i].b >> e[i].c;
			t[i][1] = e[i].a, t[i][2] = e[i].b, t[i][3] = e[i].c;
			if(e[i].a == max(max(e[i].a, e[i].b), e[i].c)) e[i].mx = e[i].a, e[i].mxid = 1;
			else if(e[i].b == max(max(e[i].a, e[i].b), e[i].c)) e[i].mx = e[i].b, e[i].mxid = 2;
			else if(e[i].c == max(max(e[i].a, e[i].b), e[i].c)) e[i].mx = e[i].c, e[i].mxid = 3;	
		}
		
		if(n == 2){
			ans = -1;
			ans = max(ans, e[1].a + e[2].b);
			ans = max(ans, e[1].a + e[2].c);
			ans = max(ans, e[1].b + e[2].a);
			ans = max(ans, e[1].b + e[2].c);
			ans = max(ans, e[1].c + e[2].a);
			ans = max(ans, e[1].c + e[2].b);
			cout << ans << endl;
			continue;
		}
		
		if(n <= 20){
			query(1, 0, 0, 0, 0);
			cout << ans << endl;
			continue;
		}
		
		sort(e + 1, e + n + 1, cmp);
		
		k = n / 2;
		for(int i = 1;i <= n;i ++){
			if(cnt[e[i].mxid] < k){
				ans += e[i].mx;
				cnt[e[i].mxid] ++;
			}else{
				if(e[i].mxid == 1){
					if(e[i].b > e[i].c && cnt[2] < k){
						cnt[2] ++;
						ans += e[i].b;
					}else if(e[i].c >= e[i].b && cnt[3] < k){
						cnt[3] ++;
						ans += e[i].c;
						
					}
					continue;
				}else if(e[i].mxid == 2){
					if(e[i].a > e[i].c && cnt[1] < k){
						cnt[1] ++;
						ans += e[i].a;
					}else if(e[i].c >= e[i].a && cnt[3] < k){
						cnt[3] ++;
						ans += e[i].c;
						
					}
					continue;
				}else if(e[i].mxid == 3){
					if(e[i].b > e[i].a && cnt[2] < k){
						cnt[2] ++;
						ans += e[i].b;
					}else if(e[i].a >= e[i].b && cnt[1] < k){
						cnt[1] ++;
						ans += e[i].a;
						
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}