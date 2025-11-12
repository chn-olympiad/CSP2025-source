#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>inline void read(T &x){
	x = 0; T w = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-')	w = -1; ch = getchar();}
	while (isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x *= w;
}
template<typename T>inline void write(T x){
	if (x < 0)	putchar('-'), x = ~(x - 1);
	if (x > 9)	write(x / 10);
	putchar(x % 10 ^ 48);
}

const int N = 1e5 + 5;

int T;

struct node{
	int del, id;
}tt[2][N];
int tp0, tp1;
bool cmp(node alp, node bet){
	return alp.del > bet.del;
}
bool vis[N];

int n, a[N][4];
int tong[4][N], ans1, ans2, ans3, sy1, sy2, sy3;
int sum;

int main(){
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
//	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

	read(T);
	while (T--){
		read(n), ans1 = ans2 = ans3 = sum = tp0 = tp1 = 0;
		for (int i = 1, ma; i <= n; ++i){
			read(a[i][1]), read(a[i][2]), read(a[i][3]), ma = max(a[i][1], max(a[i][2], a[i][3]));
			if (ma == a[i][1])	tong[1][++ans1] = i;
			else	if (ma == a[i][2])	tong[2][++ans2] = i;
			else	tong[3][++ans3] = i;
			vis[i] = false;
		}
		for (int i = 1; i <= ans1; ++i)	sum += a[tong[1][i]][1];
		for (int i = 1; i <= ans2; ++i)	sum += a[tong[2][i]][2];
		for (int i = 1; i <= ans3; ++i)	sum += a[tong[3][i]][3];
		if (ans1 > n / 2){
			sy1 = ans1 - n / 2, sy2 = n / 2 - ans2, sy3 = n / 2 - ans3;
			for (int i = 1, tmp; i <= ans1; ++i){
				tmp = tong[1][i];
				tt[0][++tp0] = (node){a[tmp][2] - a[tmp][1], tmp};
				tt[1][++tp1] = (node){a[tmp][3] - a[tmp][1], tmp};
			}
			sort(tt[0] + 1, tt[0] + tp0 + 1, cmp);
			sort(tt[1] + 1, tt[1] + tp1 + 1, cmp);
			tt[0][tp0 + 1] = tt[1][tp1 + 1] = (node){0, -1e5};
			int i1 = 1, j1 = 1, cnt1 = 0, cnt2 = 0;
			while (true){
				if ((cnt1 + cnt2 >= sy1 || (i1 > tp0 && j1 > tp1)))	break;
				while (vis[tt[0][i1].id] == true && i1 <= tp0)	++i1;
				while (vis[tt[1][j1].id] == true && j1 <= tp1)	++j1;
				if (tt[0][i1].id == tt[1][j1].id){
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
						else	if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del;
						}
					}
					else{
						if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					vis[tt[0][i1].id] = true, ++i1, ++j1;
				}
				else{
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
						else	if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
					}
					else{
						if (cnt1 < sy2){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
				}
			}
		}
		else	if (ans2 > n / 2){
			sy2 = ans2 - n / 2, sy1 = n / 2 - ans1, sy3 = n / 2 - ans3;
			for (int i = 1, tmp; i <= ans2; ++i){
				tmp = tong[2][i];
				tt[0][++tp0] = (node){a[tmp][1] - a[tmp][2], tmp};
				tt[1][++tp1] = (node){a[tmp][3] - a[tmp][2], tmp};
			}
			sort(tt[0] + 1, tt[0] + tp0 + 1, cmp);
			sort(tt[1] + 1, tt[1] + tp1 + 1, cmp);
			tt[0][tp0 + 1] = tt[1][tp1 + 1] = (node){0, -1e5};
			int i1 = 1, j1 = 1, cnt1 = 0, cnt2 = 0;
			while (true){
				if ((cnt1 + cnt2 >= sy2 || (i1 > tp0 && j1 > tp1)))	break;
				while (vis[tt[0][i1].id] == true && i1 <= tp0)	++i1;
				while (vis[tt[1][j1].id] == true && j1 <= tp1)	++j1;
				if (tt[0][i1].id == tt[1][j1].id){
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
						else	if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
					}
					else{
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					vis[tt[0][i1].id] = true, ++i1, ++j1;
				}
				else{
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
						else	if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
					}
					else{
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy3){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
				}
			}
		}
		else	if (ans3 > n / 2){
			sy3 = ans3 - n / 2, sy1 = n / 2 - ans1, sy2 = n / 2 - ans2;
			for (int i = 1, tmp; i <= ans3; ++i){
				tmp = tong[3][i];
				tt[0][++tp0] = (node){a[tmp][1] - a[tmp][3], tmp};
				tt[1][++tp1] = (node){a[tmp][2] - a[tmp][3], tmp};
			}
			sort(tt[0] + 1, tt[0] + tp0 + 1, cmp);
			sort(tt[1] + 1, tt[1] + tp1 + 1, cmp);
			tt[0][tp0 + 1] = tt[1][tp1 + 1] = (node){0, -1e5};
			int i1 = 1, j1 = 1, cnt1 = 0, cnt2 = 0;
			while (true){
				if ((cnt1 + cnt2 >= sy3 || (i1 > tp0 && j1 > tp1)))	break;
				while (vis[tt[0][i1].id] == true && i1 <= tp0)	++i1;
				while (vis[tt[1][j1].id] == true && j1 <= tp1)	++j1;
				if (tt[0][i1].id == tt[1][j1].id){
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del;
						}
						else	if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
					}
					else{
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del;
						}
						else	if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del;
						}
					}
					vis[tt[0][i1].id] = true, ++i1, ++j1;
				}
				else{
					if (tt[0][i1].del > tt[1][j1].del){
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
					else	if (tt[0][i1].del < tt[1][j1].del){
						if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
						else	if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
					}
					else{
						if (cnt1 < sy1){
							++cnt1, sum += tt[0][i1].del, vis[tt[0][i1].id] = true, ++i1;
						}
						else	if (cnt2 < sy2){
							++cnt2, sum += tt[1][j1].del, vis[tt[1][j1].id] = true, ++j1;
						}
					}
				}
			}
		}
		write(sum), putchar('\n');
	}

	return 0;
}
