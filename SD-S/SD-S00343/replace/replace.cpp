#include <bits/stdc++.h>

using namespace std;

inline LL read(){
	LL x = 0,f = 1;
	char c = getchar();
	while(c > '9'|| c < '0'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' &&c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * f;
}

LL n, m;

int main(){	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return 0;	
}

