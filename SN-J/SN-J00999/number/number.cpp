#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char str[1000001];
	cin >> s;
	int c = 1;	
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			str[c] = s[i];
			c++;
		}	
	}
	for(int i = 1;i <= c;i++){
		if(int(str[i]) >= int(str[i + 1]) && int(str[i + 1]) != 0){
			swap(str[i],str[i + 1]);
		}	
	for(int i = s.size();i >= 1;i--){	
			cout << str[i];
	}
	return 0;
}
