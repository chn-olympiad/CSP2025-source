#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

const int N = 5e6+86;

ll cost , cnt;
ll rec[20][N];
typedef tuple<ll,ll,ll> p; // w,u,v
priority_queue<p , vector<p> , greater<p> > que;


inline void add(ll u,ll v,ll w){
	que.emplace(w,u,v);
}

int fa[N];
inline ll find(ll x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline void merge(ll x , ll y){
	fa[find(y)] = find(x);
}


int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

	ll n,m,K;
	cin >> n >> m >> K;
	for(ll i = 1;i <= m;i++){
		ll u,v,w;
		cin >> u >> v >> w;
		add(u,v,w); // 只需要建单向边就 OK
	}
	for(ll k = n + 1;k <= n + K;k++){
		ll c; cin >> c;
		for(ll v = 1;v <= n;v++){
			cin >> rec[k - n][v];
		}
		for(ll u = 1;u <= n;u++){
			for(ll v = u + 1;v <= n;v++){
				add(u , v , rec[k - n][u] + c + rec[k - n][v]);
			}
		}
	}
	for(ll i = 1;i <= n;i++) fa[i] = i;

	while(!que.empty()){
		auto [w,u,v] = que.top();
		que.pop();
		if(find(u) != find(v)){
			cnt ++;
			merge(u,v);
			cost += w;
		}
		if(cnt == n - 1){
			cout << cost;
			return 0;
		}
	}

    return 0;
}
