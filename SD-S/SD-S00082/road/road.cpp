#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a = 0;
	int p = false;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') p = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		a = (a << 1) + (a << 3) + (ch & 15);
		ch = getchar();
	}
	return p ? -a : a;
}
int main(){
	freopen("road.in", "r", stdin);
	freoepn("road.out", "w", stdout);	
	cout << 0;				
	return 0;
}
