#include<bits/stdc++.h>
using namespace std;

int data[10];

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	
	cin >> s;
	
	for(int i = 0; s[i]; i ++)
		if(s[i] >= '0' && s[i] <= '9')
			data[s[i] - '0'] ++;


	for(int i = 9; i >= 0; i --)
		while(data[i] != 0){
			printf("%d", i);
			data[i] --;
		}
	
	puts("");
	
	return 0;
}