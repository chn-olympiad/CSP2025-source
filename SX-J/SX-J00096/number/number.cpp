#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int chr_to_int(char c){
	return (int)(c) - 48;
}
char fmax(string s){
	char result = '0';
	for (int i = 0;i < s.length();i++){
		if (s[i] > result){
			result = s[i];
		}
	}
	return result;
}
char fmin(string s){
	char result = '9';
	for (int i = 0;i < s.length();i++){
		if (s[i] < result){
			result = s[i];
		}
	}
	return result;
}
int up_int(double a){
	if (a > floor(a)){
		return floor(a)+1;
	}
	else{
		return floor(a);
	}
}
int fidx(string s,char c){
	for (int i = 0;i < s.length();i++){
		if (s[i] == c){
			return i;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	scanf("%s",&s);
	if (s.length() == 1 && (s[0] >= '1' && s[0] <= '9')){
		cout << s[0];
		return 0;
	}
	string number = "";
	for (int i = 0;i < s.length();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			number += s[i];
		}
	}
	string result = "";
	for (int i = 0;i < number.length();i++){
		result += ' ';
	}
	int idx = 0,idx1 = number.length()-1;
	int tmp = number.length();
	for (int i = 1;i <= up_int(tmp*1.0 / 2);i++){
		char c1 = fmax(number),c2 = fmin(number);
		result[idx++] = c1;
		result[idx1--] = c2;
		number.erase(fidx(number,c1),1);
		if (!number.empty()){
			number.erase(fidx(number,c2),1);
		}
	}
	cout << result;
	return 0;
}