#include <bits/stdc++.h>
using namespace std;
#define For(x,y,z) for(int x = y;x <= z;x++)
using ll = long long;

inline int read() {
	int x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

inline ll readl() {
	ll x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

int n;
int a[100010][4];
int cnt[10];
// 1:1,2:2,3:3
struct node{
	int d,x,le;
	bool operator<(const node &rhs) const{
		return d > rhs.d;
	}
};
vector<node> b[5]; 

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cout << "new edition";
	int t=read();
	while(t--){
		n=read();
		b[1].clear(),b[2].clear(),b[3].clear();
		cnt[1] = cnt[2] = cnt[3] = 0;
		For(i,1,n){
			a[i][1] = read(),a[i][2] = read(),a[i][3] = read();
			int mx = max(a[i][1],max(a[i][2],a[i][3]));
			if(mx == a[i][1]) cnt[1]++,b[1].push_back({a[i][1]-max(a[i][2],a[i][3]),i,max(a[i][2],a[i][3])});
			else if(mx == a[i][2]) cnt[2]++,b[2].push_back({a[i][2]-max(a[i][1],a[i][3]),i,max(a[i][1],a[i][3])});
			else cnt[3]++,b[3].push_back({a[i][3]-max(a[i][2],a[i][1]),i,max(a[i][2],a[i][1])}); 
		}
//		cout << n << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
		if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2){
			int ans = 0;
			For(i,1,n){
				ans += max(max(a[i][1],a[i][3]),a[i][2]);
			}
			cout << ans << "\n";
		}else{
//			cout << t << endl;
			int ans = 0;
			int cr;
			if(cnt[1] > n/2) cr = 1;
			else if(cnt[2] > n/2) cr = 2;
			else cr = 3;
			sort(b[cr].begin(),b[cr].end());
//			cout << cr << endl;
			int j = 1;
			for(auto i : b[cr]){
//				cerr << cr << " " << i.x << " " << i.d << " " << i.le << endl;
				if(j <= n/2){
					ans += a[i.x][cr];
//					cerr << ":::" << a[i.x][cr] << endl;
				}else{
					ans += i.le;
//					cerr << i.le << endl;
				}
				j++;
			}
			For(i,1,3){
				if(i == cr) continue;
				for(auto j : b[i]) ans += a[j.x][i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}