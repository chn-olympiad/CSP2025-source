#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

ll n;
bool vis[MAXN];
struct Node{
	ll v1, v2, v3, id;
}a[MAXN], b[MAXN], c[MAXN];
vector <int> g1, g2, g3;

bool cmp1(int x, int y){
	return max(a[x].v2-a[x].v1, a[x].v3-a[x].v1) > max(a[y].v2-a[y].v1, a[y].v3-a[y].v1);
}
bool cmp2(int x, int y){
	return max(a[x].v3-a[x].v2, a[x].v1-a[x].v2) > max(a[y].v3-a[y].v2, a[y].v1-a[y].v2);
}
bool cmp3(int x, int y){
	return max(a[x].v1-a[x].v3, a[x].v2-a[x].v3) > max(a[y].v1-a[y].v3, a[y].v2-a[y].v3);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--){
		n = read();
		g1.clear(), g2.clear(), g3.clear();
		for(int i = 1; i <= n; i++)
			a[i].v1 = read(), a[i].v2 = read(), a[i].v3 = read(), a[i].id = i, b[i] = c[i] = a[i];
		ll ans = 0, sum = 0;
		for(int i = 1; i <= n; i++){
			ll mx = max(a[i].v1, max(a[i].v2, a[i].v3));
			if(a[i].v1 == mx) ans += a[i].v1, g1.push_back(i);
			else if(a[i].v2 == mx) ans += a[i].v2, g2.push_back(i);
			else if(a[i].v3 == mx) ans += a[i].v3, g3.push_back(i);
		}
		if(g1.size() > n/2){
			sort(g1.begin(), g1.end(), cmp1);
			int x = g1.size() - n/2;
			int len = g1.size();
			for(int i = 0; i < x; i++){
				int id = g1[i];
				ans += max(a[id].v2-a[id].v1, a[id].v3-a[id].v1);
			}
		}else if(g2.size() > n/2){
			sort(g2.begin(), g2.end(), cmp2);
			int x = g2.size() - n/2;
			int len = g2.size();
			for(int i = 0; i < x; i++){
				int id = g2[i];
				ans += max(a[id].v3-a[id].v2, a[id].v1-a[id].v2);
			}
		}else if(g3.size() > n/2){
			sort(g3.begin(), g3.end(), cmp3);
			int x = g3.size() - n/2;
			int len = g3.size();
			for(int i = 0; i < x; i++){
				int id = g3[i];
				ans += max(a[id].v1-a[id].v3, a[id].v2-a[id].v3);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}


// Ren5Jie4Di4Ling5%
