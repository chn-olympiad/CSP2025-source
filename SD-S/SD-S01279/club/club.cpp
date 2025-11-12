#include<bits/stdc++.h>
using namespace std;
bool STSTST;

const int N = 1e5 + 5;

struct node{
	int x,y,z;
	const bool operator<(const node &a)const{return (x == a.x ? (y == a.y ? z > a.z : y < a.y) : x < a.x);}
};

struct node1{
	int x,y,z;
	const bool operator<(const node1 &a)const{return (y == a.y ? z < a.z : y < a.y);}
};

int n,a[N],b[N],c[N],cnt[5],vis[N],ans;
priority_queue<node> q1,q2,q3;
priority_queue<node1> q[5];

bool EDEDED;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
//	struct _timeb TT;
//	_ftime(&TT);
//	default_random_engine rng(TT.millitm);
//	mt19937 rnd(TT.millitm);
	
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		ans = 0;
		for (int i = 1;i <= n;++i){
			cin >> a[i] >> b[i] >> c[i];
			q1.push({a[i],max(b[i],c[i]) - a[i],i});
			q2.push({b[i],max(a[i],c[i]) - b[i],i});
			q3.push({c[i],max(b[i],a[i]) - c[i],i});
		}for (int i = 1;i <= n;++i){
			node cur;
			int fleg = 0;
			while (1){
				if (q1.size() && ((q2.empty() || q2.top().x <= q1.top().x) && (q3.empty() || q3.top().x <= q1.top().x))){
					if (vis[q1.top().z]) q1.pop();
					else{
						cur = q1.top();
						q1.pop();
						fleg = 1;
						break;
					}
				}else if (q2.size() && ((q1.empty() || q1.top().x <= q2.top().x) && (q3.empty() || q3.top().x <= q2.top().x))){
					if (vis[q2.top().z]) q2.pop();
					else{
						cur = q2.top();
						q2.pop();
						fleg = 2;
						break;
					}
				}else{
					if (vis[q3.top().z]) q3.pop();
					else{
						cur = q3.top();
						q3.pop();
						fleg = 3;
						break;
					}
				}
			}
			if (cnt[fleg] == (n >> 1)){
				if (ans + q[fleg].top().y + cur.x <= ans + cur.x + cur.y){
					--i;
					continue;
				}else{
					vis[cur.z] = 1;
					ans += cur.x + q[fleg].top().y;
					q[fleg].pop();
					q[fleg].push({cur.x,cur.y,cur.z});
				}
			}else{
				vis[cur.z] = 1;
				ans += cur.x;
				cnt[fleg]++;
				q[fleg].push({cur.x,cur.y,cur.z});
			}
		}cout << ans;
		if (T) cout << '\n';
		for (int i = 1;i <= n;++i) vis[i] = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		while (q1.size()) q1.pop();
		while (q2.size()) q2.pop();
		while (q3.size()) q3.pop();
		while (q[1].size()) q[1].pop();
		while (q[2].size()) q[2].pop();
		while (q[3].size()) q[3].pop();
	}
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms\n";
//	cerr << "memory used: " << abs(&STSTST - &EDEDED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}
/*
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
