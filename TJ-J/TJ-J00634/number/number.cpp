#include<bits/stdc++.h>
using namespace std;
map<char,int> t;
map<int,char> d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	d[1]='1';d[2]='2';d[3]='3';d[4]='4';d[5]='5';d[6]='6';d[7]='7';d[8]='8';d[9]='9';d[0]='0';
	string s;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			t[s[i]]++;
		}
	}
	for(int j = 9;j>=0;j--){
		while(t[d[j]]!=0){
			cout << j;
			t[d[j]]--;
		}
	}
	return 0;
}

