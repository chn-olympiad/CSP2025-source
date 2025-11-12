// 4*5 + 5(A) + 3*5(B) = 30 

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

namespace noip {
typedef long long Int;

struct Member {
	Int a1, a2, a3;
} m[100005];

Int n, pian1, pian2, ans, a1c, sa1, sa2;

bool cmpA(const Member& a, const Member& b) {
	return a.a1 == b.a1 ? a.a1-a.a2 < b.a1-b.a2 : a.a1 < b.a1;
}

bool operator> (const Member& a, const Member& b) {
	return a.a1-a.a2 > b.a1-b.a2;	
}

void ss(Int i, Int s1, Int s2, Int s3, Int s) {
	if (s1+s2+s3 == n) {
		ans = std::max(s, ans);
		return;
	}
	if (s1 < n/2) noip::ss(i+1, s1+1, s2, s3, s+m[i].a1);
	if (s2 < n/2) noip::ss(i+1, s1, s2+1, s3, s+m[i].a2);
	if (s3 < n/2) noip::ss(i+1, s1, s2, s3+1, s+m[i].a3);
}

void main() {
	std::cin >> n;
	for (Int i = 1; i <= n; i++) {
		std::cin >> m[i].a1 >> m[i].a2 >> m[i].a3;
		pian1 += m[i].a2; pian2 += m[i].a3;
	}
	
	
	if (n <= 30) {
		ans = 0;
		m[0].a1 = 0; m[0].a2 = 0; m[0].a3 = 0;
		noip::ss(1, 0, 0, 0, 0);
		std::cout << ans << std::endl;
	}
	else if (pian1 == 0 && pian2 == 0) {
		std::sort(m+1, m+n+1, cmpA);
		ans = 0;
		for (Int i = n; i > n/2; i--) ans += m[i].a1;
		std::cout << ans << std::endl;
	}
	else if (pian2 == 0) {
		std::sort(m+1, m+n+1, cmpA);
		a1c = 0; ans = 0;
		std::priority_queue<
			Member,
			std::vector<Member>,
			std::greater<Member>
		> q;
		for (Int i = 1; i <= n; i++) {
			q.push(m[i]);
			ans += m[i].a1;
			a1c++;
			if (a1c > n/2) {
				
				sa1 = q.top().a1, sa2 = q.top().a2;
				//std::cout << "now i=" << i << " pop " << sa1 << ' ' << sa2 << std::endl;
				q.pop();
				ans -= sa1; ans += sa2;
				a1c--;
			}
		}
		std::cout << ans << std::endl;
	}
}
} int main() {
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	int t; std::cin >> t;
	while (t--) noip::main();
	return 0;
}
