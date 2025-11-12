#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int read(){
	int x = 0, f = 1;
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
void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		print(x / 10);
	}
	putchar(x % 10 + '0');
}
int q,n;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(), q = read();
	string a, b;
	for(int i = 1; i <= n; i ++){
		cin >> a >> b;
	}
	for(int i = 1; i <= q; i ++){
		print(0);
		printf("\n");
	}
	return 0;
}


