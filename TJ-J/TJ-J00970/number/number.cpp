#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	//freopen ("number.in","r",stdin);
	//freopen ("number.out","w",stdout);
	string s;
	cin >> s;
		for(int j = 1;j <= s.length();j++){
			if(s[j] == '0'){
				a[0]++;
				cout <<'0';
			if(s[j] == '1'){
				a[1]++;
				cout << 1;
			}
			else if(s[j] == '2'){
				a[2]++;
				cout << 2;
			}
			else if(s[j] == '3'){
				a[3]++;
				cout << 3;
			}
			else if(s[j] == '4'){
				a[4]++;
				cout << 4;
			}
			else if(s[j] == '5'){
				a[5]++;
				cout << 5;
			}
			else if(s[j] == '6'){
				a[6]++;
				cout << 6;
			}
			else if(s[j] == '7'){
				a[7]++;
				cout << 7;
			}
			else if(s[j] == '8'){
				a[8]++;
				cout << 8;
			}
			else if(s[j] == '9'){
				a[9]++;
				cout <<9;
			}
		}
	for(int i = 9;i <= 0;i--){
		for(int j =1;j <= a[i];j++){
			cout <<i;
		}
	}
	return 0;
}
} 
