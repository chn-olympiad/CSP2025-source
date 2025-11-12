#include<bits/stdc++.h>
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)

struct Club{
	int x, y, z;
	int d, Max, Min, Mid;
	
	inline void Ad() {
		Max = max(x, max(y, z));
		Min = min(x, min(y, z));
		Mid = x + y + z - Max - Min;
		d = Max - Mid;
	}
}a[100005];

int T, N;
int X, Y, Z;
int Ans;

bool cmp(Club x, Club y) {
	return x.d > y.d;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> T;
	while(T --> 0) {
		std::cin >> N;
		for(int i = 1; i <= N; i ++) 
			std::cin >> a[i].x >> a[i].y >> a[i].z, a[i].Ad();
		
		X = Y = Z = Ans = 0;
		std::sort(a + 1, a + 1 + N, cmp);
		for(int i = 1; i <= N; i ++) {
			if(a[i].x == a[i].Max) {
				if(X + 1 > N / 2) {
					Ans += a[i].Mid;
					if(a[i].Mid == a[i].y) Y ++;
					else Z ++;
				}
				else Ans += a[i].x, X ++;
			}
			else if(a[i].y == a[i].Max) {
				if(Y + 1 > N / 2) {
					Ans += a[i].Mid;
					if(a[i].Mid == a[i].x) X ++;
					else Z ++;
				}
				else Ans += a[i].y, Y ++;
			}
			else {
				if(Z + 1 > N / 2) {
					Ans += a[i].Mid;
					if(a[i].Mid == a[i].x) X ++;
					else Y ++;
				}
				else Ans += a[i].z, Z ++;
			}
		}
		
		std::cout << Ans <<'\n';
	}
	return 0;
}
