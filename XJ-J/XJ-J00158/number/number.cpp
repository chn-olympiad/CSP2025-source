#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	string a;
	cin >> s;
	for( int i = 1;i  <= s.size();i++){
		for(int i = 1;i <= s.ize();i++){
			if(s[i] > s[i - 1]){
				swap(s[i],s[i-1]);
			}
		}
	}
	for(int i = 0; i <= s.size();i++){
		cout << int(s[i])-48;
	}
	return 0;
}
