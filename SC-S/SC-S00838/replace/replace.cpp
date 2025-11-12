#include <bits/stdc++.h>

void file(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return;
}

const int sp = 2e5 + 5;

int n;
std::string s1[sp], s2[sp], t1, t2;
int ss[sp], beg[sp], end[sp];

int main(){
	file();
	int T;
	std::cin >> n >> T;
	for(int i = 1; i <= n; ++ i){
		std::cin >> s1[i] >> s2[i];
		ss[i] = s1[i].size();
		int bg = -1, ed = -1;
		for(int j = 0; j < ss[i]; ++ j){
			if(s1[i][j] != s2[i][j]){
				bg = j;
				break;
			}
		}
		for(int j = ss[i] - 1; j >= 0; -- j){
			if(s1[i][j] != s2[i][j]){
				ed = j;
				break;
			}
		}
		beg[i] = bg, end[i] = ed;
//		std::cout << beg[i] << " " << end[i] << "\n";
	}
	while(T --){
		std::cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			std::cout << "0\n";
			continue;
		}
		int ts = t1.size();
		int bg, ed;
		for(int i = 0; i < ts; ++ i){
			if(t1[i] != t2[i]){
				bg = i;
				break;
			}
		}
		for(int i = ts - 1; i >= 0; -- i){
			if(t1[i] != t2[i]){
				ed = i;
				break;
			}
		}
		int ans = 0;
//		std::cout << t1 << " " << t2 << "\n";
		for(int i = 1; i <= n; ++ i){
			if(end[i] - beg[i] != ed - bg){
				continue;
			}
			if(beg[i] > bg || ts - ed < ss[i] - end[i]){
				continue;
			}
			int sta = bg - beg[i], fin = ed + (ss[i] - 1 - end[i]);
//			std::cout << bg - beg[i] << " " << ed + (ss[i] - 1 - end[i]) << "\n";
//			std::cout << s1[i] << " " << s2[i] << " " << t1.substr(sta, (fin - sta + 1)) << " " << t2.substr(sta, (fin - sta + 1)) << "\n";
			if(s1[i] == t1.substr(sta, (fin - sta + 1)) && s2[i] == t2.substr(sta, (fin - sta + 1))){
				++ ans;
			}
		}
		std::cout << ans << "\n";
	}
	return 0;
}