#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000006],temp,key_turn;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	temp = 1;
	for(int i = 0;i <= s.size()+1; i++){
		if(s[i] == '0'){
			a[temp] = 0;
			temp++;	
		}
		if(s[i] == '1'){
			a[temp] = 1;
			temp++;
		}
		if(s[i] == '2'){
			a[temp] = 2;
			temp++;
		}
		if(s[i] == '3'){
			a[temp] = 3;
			temp++;
		}
		if(s[i] == '4'){
			a[temp] = 4;
			temp++;
		}
		if(s[i] == '5'){
			a[temp] = 5;
			temp++;
		}
		if(s[i] == '6'){
			a[temp] = 6;
			temp++;
		}
		if(s[i] == '7'){
			a[temp] = 7;
			temp++;
		}
		if(s[i] == '8'){
			a[temp] = 8;
			temp++;
		}
		if(s[i] == '9'){
			a[temp] = 9;
			temp++;
		}
	}
	for(int i = 1;i <= temp-1; i++){
		for(int j = 1;j <= temp-1; j++){
			if(a[j] < a[j + 1]){
				key_turn = a[j];
				a[j] = a[j + 1];
				a[j + 1] = key_turn;
			}
		}	
	}
	for(int i = 1;i <= temp-1;i++){
		cout << a[i];
	}
	return 0;
} 
