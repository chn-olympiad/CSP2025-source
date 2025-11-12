#include <cctype>
#include <cstdio>
#include <string>
#include <iostream>
#ifndef LOCALDEBUG
#define _getchar getchar
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#define dfex(a, b)
#else
#define _getchar getchar
#define fex(a, b)
#define dfex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=_getchar()))if(c=='-')f=-f;
	while(isdigit(c)) {
		res=res*10+c-'0';
		c=_getchar();
	}
	return res*f;
}

string s;
long long n;
long long a[15];

int main(void) {
	fex("number.in", "number.out");
//	dfex("number3.in", "number3.out");
	getline(cin, s);
	n=s.size();
	for(int i = 0; i < n; i++) {
		if(isdigit(s[i]))a[s[i]-'0']++;
	}
	for(int i = 9; i >= 0; i--)
	for(int j = 1; j <= a[i]; j++)putchar(i+'0');
	
	return 0;
} // O(n), 100 points expected.
