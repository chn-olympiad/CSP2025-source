#include<bits/stdc++.h>
using namespace std;
template <typename type>
inline void read(type &x){
	x = 0;
	static bool flag;
	flag = 0;
	char ch = getchar();
	while (!isdigit(ch)){
		flag = ch == '-';
		ch = getchar();
	} while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	} flag ? x = -x : 0;
} int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return 0;
}

