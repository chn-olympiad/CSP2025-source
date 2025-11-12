#include<bits/stdc++.h>
using namespace std;
int t[10];
char a[1000000];
int main(){
	cin >> a;
	for(int i = 0; i < 1000000;i++){
		if(a[i] == '\0'){
			//cout << i <<  endl;
			break;
		}
		if(a[i] >= '0' && a[i] <= '9'){
			//cout << (int)a[i] << endl;
			t[a[i]-48]++;
		}
	}
	for(int i = 9;i >=0;i--){
		for(int j = 0;j < t[i];j++){
			cout << i;
		}
	}
	return 0;
}
