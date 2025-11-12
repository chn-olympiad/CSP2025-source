#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mod 998244353
inline LL read(){
	LL x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(LL x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		print(x / 10);
	}
	putchar(x % 10 + '0');
}
LL n , m, sum = 1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(), m = read();
	cin >> s;
	for(int i = n; i >= 1; i --){
		sum *= i;
		sum %= mod;
	}
	print(sum);
	return 0;
}


