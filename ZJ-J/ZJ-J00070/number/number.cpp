#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

unsigned long long int x[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char ch[N] = {}; 

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> ch;
	unsigned int len = strlen(ch);
	for(int i = 0;i < len;++i){
		if ('0' <= ch[i] && ch[i] <= '9') ++ x[ch[i] - 48];
	}
	for(int i = 9;i >= 0;--i){
		if(x[i] == 0) continue;
		for(int j = 0;j < x[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
