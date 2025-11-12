#include <bits/stdc++.h>

using namespace std;

string s;
int a[10000005],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			a[cnt] = s[i] - 48;
		}
	}
	for(int i = 1;i <= cnt;i++){
		if(a[i] == 9){
			cout << a[i];
		}
	}
	for(int i = 1;i <= cnt;i++){
		if(a[i] == 8){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 7){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 6){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 5){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 4){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 3){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 2){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 1){
			cout << a[i];
		}
	}for(int i = 1;i <= cnt;i++){
		if(a[i] == 0){
			cout << a[i];
		}
	}
	return 0;
}



