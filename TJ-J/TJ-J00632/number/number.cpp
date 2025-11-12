#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005] = {};
	cin.getline(a,1000005);
	int cnt = 0,b[15] = {0};
	for(int i = 0;i < 1000005;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b[a[i] - '0']++;
			cnt++;
		}
	}
	char c[cnt + 5];
	int m = 0;
	for(int i = 9;i >= 0;i--){
		while(b[i] != 0){
			c[m] = i + '0';
			b[i]--;
			m++;
		}
	}
	for(int i = 0;i < cnt;i++){
		cout << c[i];
	}
	return 0;
} 
