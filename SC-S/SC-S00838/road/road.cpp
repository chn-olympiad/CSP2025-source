#include <bits/stdc++.h>
#define ll long long

void file(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return;
}

const int sp = 1e4 + 15;
const int spm = 1e6 + 15;
const int inf = INT_MAX;

int n, m, k;
//int mp[sp][sp];
int c[15], cs[15][sp];
int u[spm], v[spm], w[spm];
struct node{
	int val, x, y;
};
node mp[spm * 2];
int tot, ced;
int fa[sp];

bool cmp(node X, node Y){
	return X.val < Y.val;
}

int get_fa(int x){
	if(fa[x] == x){
		return x;
	}
	fa[x] = get_fa(fa[x]);
	return fa[x];
}

ll min_tree(){
	ll res = 0;
	std::sort(mp + 1, mp + ced + 1, cmp);
//	for(int i = 1; i <= ced; ++ i){
//		std::cout << mp[i].x << " " << mp[i].y << " " << mp[i].val << "\n";
//	}
	for(int i = 1; i <= tot; ++ i){
		fa[i] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= ced; ++ i){
		if(cnt >= tot - 1){
			break;
		}
		if(get_fa(mp[i].x) != get_fa(mp[i].y)){
			res += mp[i].val;
			++ cnt;
			fa[get_fa(mp[i].x)] = get_fa(mp[i].y);
		}
	}
	return res;
}

int main(){
	file();
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i){
		std::cin >> u[i] >> v[i] >> w[i];
	}
	bool flag = true;
	for(int i = 1; i <= k; ++ i){
		std::cin >> c[i];
		if(c[i] != 0){
			flag = false;
		}
		bool flagg = false;
		for(int j = 1; j <= n; ++ j){
			std::cin >> cs[i][j];
			if(cs[i][j] == 0){
				flagg = true;
			}
		}
		if(!flagg){
			flag = false;
		}
	}
	if(flag){
		tot = n, ced = m;
		for(int i = 1; i <= m; ++ i){
			node tmp;
			tmp.x = u[i], tmp.y = v[i], tmp.val = w[i];
			mp[i] = tmp;
		}
		for(int i = 1; i <= k; ++ i){
			++ tot;
			for(int j = 1; j <= n; ++ j){
				node tmp;
				tmp.x = tot, tmp.y = j, tmp.val = cs[i][j];
				++ ced;
				mp[ced] = tmp;
			}
		}
		std::cout << min_tree();
		return 0;
	}
	ll ans = 1ll * inf * inf;
	int fst = (1 << k) - 1;
	for(int st = 0; st <= fst; ++ st){
		ll cnt = 0;
		tot = n, ced = m;
		for(int i = 1; i <= m; ++ i){
			node tmp;
			tmp.x = u[i], tmp.y = v[i], tmp.val = w[i];
			mp[i] = tmp;
		}
//		std::cout << "-----\n";
//		std::cout << st << "\n";
		for(int i = 1; i <= k; ++ i){
			if((1 << (i - 1)) & st){
//				std::cout << i << " ";
				cnt += c[i];
				++ tot;
				for(int j = 1; j <= n; ++ j){
					node tmp;
					tmp.x = tot, tmp.y = j, tmp.val = cs[i][j];
					++ ced;
					mp[ced] = tmp;
				}
			}
		}
//		std::cout << "\n";
		if(cnt >= ans){
			continue;
		}
		cnt += min_tree();
		if(cnt < ans){
			ans = cnt;
		}
	}
	std::cout << ans;
	return 0;
}