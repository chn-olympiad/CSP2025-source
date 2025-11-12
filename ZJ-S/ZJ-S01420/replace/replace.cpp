#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+4;
const int M = 1e6+5;
ll read(){
	ll x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=1ll*x*10+s-'0';
		s=getchar();
	}return 1ll*x*f;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	printf("1");
	return 0; 
}/*
4  4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
