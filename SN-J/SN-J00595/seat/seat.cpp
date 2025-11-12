// SN-J00595 杜明璋 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
string s,i,n;
string s20,s21;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	cin >> n;
		for(int i = 1; i < s.size();i++){
		if (s[i] == '1')
			s20 = s[i] + s20;
		if (s[i] == '2')
			s21 = s21 + s[i];
	}
	cout << 1 << 2;
	return 0;
} 
