#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N][5],n,cnt[5],now[N];
// now[i] 表示 i 最后选的是什么颜色 
std::multiset<std::pair<int,int>> st[5][5];
void solve(){
	std::cin >> n;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= 3; ++ j){
			std::cin >> a[i][j];
		}
	}
	for(int i = 1; i <= 3; ++ i){
		for(int j = 1; j <= 3; ++ j){
			if(i != j) st[i][j].clear();
		}
		cnt[i] = 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++ i){
		int max_val = -1,sec_val = -1,max_color = 0,sec_color = 0;
		for(int j = 1; j <= 3; ++ j){
			if(a[i][j] > max_val){
				sec_val = max_val;
				sec_color = max_color;
				max_val = a[i][j];
				max_color = j;
			}else{
				if(a[i][j] > sec_val){
					sec_val = a[i][j];
					sec_color = j;
				}
			}
		}
		if(cnt[max_color] < n / 2){
			++ cnt[max_color];
			ans += max_val;
			for(int j = 1; j <= 3; ++ j){
				if(j != max_color){
					st[max_color][j].insert(std::make_pair(max_val - a[i][j],i));
				}
			}
			now[i] = max_color; 
		}else{
			// 如果这个选了不划算，就直接不选最大值
			int min_num = 1e9,min_id = 0;
			for(int j = 1; j <= 3; ++ j){
				if(j != max_color){
					if(st[max_color][j].size()){
						auto toper = *st[max_color][j].begin();
						if(min_num > toper.first){
							min_num = toper.first;
							min_id = toper.second;
						}
					}
				}
			}
			if(max_val - sec_val > min_num){
				// 这个得选最大值的颜色
				// 让 min_id 选其他的颜色
				ans -= min_num;
				ans += max_val;
				now[i] = max_color;
				int max_s = 0,max_s_id = 0,last = now[min_id];
				for(int j = 1; j <= 3; ++ j){
					if(j != last){
						st[last][j].erase(std::make_pair(a[min_id][last] - a[min_id][j],min_id));
						if(a[min_id][j] >= max_s){
							max_s = a[min_id][j];
							max_s_id = j;
						}
					}
				}
				now[min_id] = max_s_id;
				++ cnt[max_s_id];
				for(int j = 1; j <= 3; ++ j){
					if(j != max_s_id){
						st[max_s_id][j].insert(std::make_pair(max_s - a[min_id][j],min_id));
					}
				}
				for(int j = 1; j <= 3; ++ j){
					if(j != max_color){
						st[max_color][j].insert(std::make_pair(max_val - a[i][j],i));
					}
				}
			}else{
				// 此时选次大值的颜色 
				now[i] = sec_color;
				++ cnt[sec_color];
				ans += sec_val;
				for(int j = 1; j <= 3; ++ j){
					if(j != sec_color){
						st[sec_color][j].insert(std::make_pair(sec_val - a[i][j],i));
					}
				}
			}
		}
	}
	std::cout << ans << '\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while(t -- ) solve();
	return 0;
}
