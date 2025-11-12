#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.cpp","r","stdin");
	freopen("number.cpp","w","stdout");
	string s;
	cin >> s;
	string number[s.size()];
	int count_number = -1;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' and s[i] <= '9'){
			count_number ++;
			number[count_number] = s[i];
		}
	}
	count_number += 1;
	sort(number,number+count_number);
	for(int i=count_number-1;i>=0;i--){
		cout << number[i];
	}
	return 0;
}
