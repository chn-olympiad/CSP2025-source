#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
const int N = 1e5 + 10;
using tp = std::tuple<int, int, int>;
using pi = std::pair<int, int>;
int T, n; long rs; std::vector<std::pair<int, int>> a[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    for(std::cin >> T; rs = 0, T--; ){ std::cin >> n; 
		std::priority_queue<tp, std::vector<tp>, std::greater<tp>> s[4];
        for(int i = 1; i <= n; i++) a[i].clear(), a[i].resize(3);
        for(int i = 1, x, y, z; i <= n; i++){
            std::cin >> x >> y >> z;
            a[i][0] = {x, 1}, a[i][1] = {y, 2}, a[i][2] = {z, 3};
            std::sort(a[i].begin(), a[i].end(), std::greater<pi>());
            auto [w1, p1] = a[i][0]; auto [w2, p2] = a[i][1];
            rs += w1, s[p1].push({w1-w2, i, 1});
            if(s[p1].size() > n / 2){
                auto [x, id, p] = s[p1].top(); s[p1].pop(); rs -= x;
                auto [f, g] = a[id][p]; auto [h, q] = a[id][p+1];
                s[g].push({f - h, id, p + 1});
            }
        }
		std::cout << rs << '\n';
    }
}     
