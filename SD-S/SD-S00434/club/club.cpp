#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9'){if(f == '-')f = -1; c = getchar();}
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c - '0'); c = getchar();}
	return f * x;
}
int buf[40];
inline void write(ll x){
	if(!x){putchar('0');return;}
	if(x < 0){putchar('-');x = -x;}
	int len = 0;
	while(x){
		buf[++len] = x % 10;
		x /= 10;
	}
	while(len){
		putchar(buf[len] + '0');
		len--;
	}
}
ll t, n, cnt[5];
struct Node{
	ll v[5], mx, mxid, cmx, cmxid, id;
	bool operator> (const Node &ano) const {return mx - cmx > ano.mx - ano.cmx;}
}a[MAXN];
bool cmp(Node x, Node y){
	return x.mx > y.mx;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while(t--){
		n = read();
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			a[i].v[1] = read();
			a[i].v[2] = read();
			a[i].v[3] = read();
			a[i].id = i;
			a[i].mx = max(a[i].v[1], max(a[i].v[2], a[i].v[3]));
			if(a[i].mx == a[i].v[1]){
				a[i].mxid = 1, a[i].cmx = max(a[i].v[2], a[i].v[3]);
				if(a[i].v[2] > a[i].v[3])
					a[i].cmxid = 2;
				else
					a[i].cmxid = 3;
			}
			if(a[i].mx == a[i].v[2]){
				a[i].mxid = 2, a[i].cmx = max(a[i].v[1], a[i].v[3]);
				if(a[i].v[1] > a[i].v[3])
					a[i].cmxid = 1;
				else
					a[i].cmxid = 3;
			}
			if(a[i].mx == a[i].v[3]){
				a[i].mxid = 3, a[i].cmx = max(a[i].v[2], a[i].v[1]);
				if(a[i].v[2] > a[i].v[1])
					a[i].cmxid = 2;
				else
					a[i].cmxid = 1;
			}
//			cout << a[i].mx << ' ' << a[i].cmx << '\n';
		}
//		puts("");
		cnt[1] = cnt[2] = cnt[3] = 0;
		sort(a + 1, a + n + 1, cmp);
//		for(int i = 1; i <= n; i++)
//			cout << a[i].v[1] << ' ' << a[i].v[2] << ' ' << a[i].v[3] << '\n';
		priority_queue <Node, vector <Node>, greater<Node> > q[4];
		for(int i = 1; i <= n; i++){
			Node now = a[i];
//			cout << i << '\n';
			if(cnt[now.mxid] == n / 2){
				Node k = q[now.mxid].top();
				if(k.mx + now.cmx < k.cmx + now.mx){
					q[now.mxid].pop();
					q[now.mxid].push(now);
					ans += now.mx + k.cmx - k.mx;
//					cout << k.id << "rep" << i << '\n';
					cnt[now.cmxid]++;
				}
				else{
//					cout << k.id << "nrep" << i << '\n';
					ans += now.cmx;
					cnt[now.cmxid]++;
				}
			}
			else{
//				cout << i << '\n';
				cnt[now.mxid]++;
				ans += now.mx;
				q[now.mxid].push(now);
			}
		}
//		cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		write(ans);
		putchar('\n');
	}
	return 0;
}
