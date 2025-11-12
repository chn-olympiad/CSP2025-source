#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Edge{
	pair<int,int> a, b, c;
	bool operator<(const Edge& other) const{
		if(a.first == other.a.first){
			return b.first == other.b.first ? c.first < other.c.first : b.first < other.b.first;
		} else {
			return a.first < other.a.first;
		}
	}
};
Edge p[N];

int n, lv;//sahngyidiandexiayigequanzhi
char lv_x;//shangyidianchulidebianhao
deque<pair<int, int>> bh[4];
deque<int> bb[4];
int sum_p[4] = {0};

void go_in(int k, char bm){
	int p_maxx = n / 2;
	int p_num;
	
	if(bm == 'a') p_num = p[k].a.second; // bumenbianhao
	else if(bm == 'b') p_num = p[k].b.second;
	else p_num = p[k].c.second;
	
	int vall;//yubeiquanzhi
	if(bm == 'a') vall = p[k].b.first;
	else if(bm == 'b') vall = p[k].c.first;
	
	int v;//dangqianquanzhi
	if(bm == 'a') v = p[k].a.first;
	else if(bm == 'b') v = p[k].b.first;
	else v = p[k].c.first;
	
	if(sum_p[p_num] < p_maxx){
		sum_p[p_num]++;
		if(bm == 'a') {
			bh[p_num].push_back(p[k].a);
//			cout << bh[p_num].front().first << " ";
		} else if(bm == 'b') {
			bh[p_num].push_back(p[k].b);
		} else {
			bh[p_num].push_back(p[k].c);
		}
		bb[p_num].push_back(k);
//		cout << lv << " ";
	} else {
		if(p[bb[p_num].front()].a.first == bh[p_num].front().first) {
			lv = p[bb[p_num].front()].b.first;
			lv_x = 'a';
		} else if (p[bb[p_num].front()].b.first == bh[p_num].front().first) {
			lv = p[bb[p_num].front()].c.first;
			lv_x = 'b';
		} else {
			lv_x = 'c';
		}
//		cout << k << " " << bh[p_num].front().first << " " << vall << " " << lv << " " << v << endl;
		if(bh[p_num].front().first + vall > lv + v){
			go_in(k, (char)bm + 1);
		} else {
			auto temp = bb[p_num].front();
			bh[p_num].pop_front();
			bb[p_num].pop_front();
			go_in(temp, (char)lv_x + 1);
			go_in(k, bm);
		}
	}
	return ;
}

void solve(){
	scanf("%d", &n);
	bool A = true;
	for(int i = 1; i <= n; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(y != 0 || z != 0) A = false;
		if(x > y){
			if(y > z){
				p[i].a = {x, 1};
				p[i].b = {y, 2};
				p[i].c = {z, 3};
			} else {
				if(z < x){
					p[i].a = {x, 1};
					p[i].b = {z, 3};
					p[i].c = {y, 2};
				} else {
					p[i].a = {z, 3};
					p[i].b = {x, 1};
					p[i].c = {y, 2};
				}
			}
		} else {
			if(x > z){
				p[i].a = {y, 2};
				p[i].b = {x, 1};
				p[i].c = {z, 3};
			} else {
				if(z < y){
					p[i].a = {y, 2};
					p[i].b = {z, 3};
					p[i].c = {x, 1};
				} else {
					p[i].a = {z, 3};
					p[i].b = {y, 2};
					p[i].c = {x, 3};
				}
			}
		}
	}
	sort(p + 1, p + n + 1);
	int ans = 0;
	if(A == true){
		for(int i = n; i > n / 2; i--){
			ans = ans + p[i].a.first;
		}
		printf("%d\n", ans);
		return ;
	}
	for(int i = 1; i <= n; i++){
		go_in(i, 'a');
	}
//	cout << endl;
	for(int i = 1; i <= 3; i++){
		int len = bh[i].size();
		for(int j = 1; j <= len; j++){
//			cout << bh[i].front().first << " ";
			ans += bh[i].front().first;
			bh[i].pop_front();
		}
//		cout << endl;
	}
	printf("%d\n", ans);
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		solve();
	}
	return 0;
}