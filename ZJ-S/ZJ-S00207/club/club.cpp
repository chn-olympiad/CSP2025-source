#include<bits/stdc++.h>
typedef long long Int;
typedef std:: pair<Int, Int> pInt;
typedef std:: pair<pInt, pInt> ppInt;
constexpr Int MAXN = 100000;
Int T, N, num1, num2, num3, ans;
ppInt A[1 + MAXN];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std:: ios:: sync_with_stdio(false);
	std:: cin.tie(nullptr);
	std:: cin >> T;
	while (T--){
		ans = num1 = num2 = num3 = 0LL;
		std:: cin >> N;
		for (Int i = 1 ; i <= N ; i++){
			pInt a, b, c;
			std:: cin >> a.first >> b.first >> c.first;
			a.second = 1, b.second = 2, c.second = 3;
			if (a.first < b.first) std:: swap(a, b);
			if (a.first < c.first) std:: swap(a, c);
			if (b.first < c.first) std:: swap(b, c);
			A[i].first = a, A[i].second = b; 
		}
		std:: sort(A + 1, A + N + 1, [](ppInt X, ppInt Y){
			return X.first.first - X.second.first > Y.first.first - Y.second.first;
		});
		for (Int i = 1 ; i <= N ; i++){
			if (A[i].first.second == 1){
				if (num1 == N / 2){
					ans += A[i].second.first;
				} else {
					ans += A[i].first.first;
					num1++;
				}
			} else if (A[i].first.second == 2){
				if (num2 == N / 2){
					ans += A[i].second.first;
				} else {
					ans += A[i].first.first;
					num2++;
				}
			} else {
				if (num3 == N / 2){
					ans += A[i].second.first;
				} else {
					ans += A[i].first.first;
					num3++;
				}
			}
		}
		std:: cout << ans << '\n';
	}
	return 0;
}

