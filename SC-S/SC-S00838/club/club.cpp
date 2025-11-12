#include <bits/stdc++.h>

void file(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return;
}

const int sp = 1e5 + 5;

int n;
struct student{
	int a, b, c, fav, sub;
}stu[sp];

bool cmp(student x, student y){
	return x.sub < y.sub;
}

int main(){
	file();
	int T;
	std::cin >> T;
	while(T --){
//		std::cout << "----\n";
		std::cin >> n;
		int ca = 0, cb = 0, cc = 0, ans = 0;
		for(int i = 1; i <= n; ++ i){
			int A, B, C;
			std::cin >> A >> B >> C;
			int mx = std::max(A, std::max(B, C));
			int mn = std::min(A, std::min(B, C));
			int md = A + B + C - mx - mn;
			stu[i].a = A, stu[i].b = B, stu[i].c = C;
			ans += mx;
			if(mx == A){
				++ ca;
				stu[i].fav = 1;
			}
			else if(mx == B){
				++ cb;
				stu[i].fav = 2;
			}
			else{
				++ cc;
				stu[i].fav = 3;
			}
			stu[i].sub = mx - md;
		}
		int k = n / 2;
		if(ca <= k && cb <= k && cc <= k){
			std::cout << ans << "\n";
		}
		else{
			std::sort(stu + 1, stu + n + 1, cmp);
			int ttt, tmp;
			if(ca > k){
				ttt = 1;
				tmp = ca - k;
			}
			else if(cb > k){
				ttt = 2;
				tmp = cb - k;
			}
			else{
				ttt = 3;
				tmp = cc - k;
			}
//			std::cout << tmp << "\n";
			for(int i = 1; i <= n; ++ i){
				if(stu[i].fav != ttt){
					continue;
				}
				ans -= stu[i].sub;
				-- tmp;
				if(tmp == 0){
					break;
				}
			}
			std::cout << ans << "\n";
		}
	}
	return 0;
}