#include<bits/stdc++.h>
using namespace std;
char a[1000100];
char b[1000100];
char mysort(char x, char y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a + 1;
	int strl = strlen(a + 1), i1 = 1;
	for(int i = 1; i <= strl; i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b[i1] = a[i];
			i1++;
		}
	}
	sort(b + 1, b + i1 + 1, mysort);
	for(int i = 1; i < i1; i++){
		printf("%c", b[i]);
	}
	return 0;
}
