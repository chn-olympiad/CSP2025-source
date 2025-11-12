#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 105;
int n, m, cnt;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	int a = read();
	for(int i = 2, x; i <= n * m; i++)
		x = read(), cnt += (x >= a ? 1 : 0);
	cnt++;
	int c = cnt / n + (cnt % n ? 1 : 0), r;
	if(c % 2){
		if(cnt % n == 0) r = n;
		else r = cnt % n;
	}else{
		if(cnt % n == 0) r = 1;
		else r = n - cnt % n + 1;
	}
	cout<< c<< ' '<< r<< "\n";
	fclose(stdin), fclose(stdout);
	return 0;
}
