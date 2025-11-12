#include<bits/stdc++.h>
using namespace std;
string s,res;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char ch:s){
		if(ch >= '0' && ch <= '9'){
			res = res + ch;
		}
	}
	sort(res.begin(),res.end(),greater<char>());
	cout << res;
	return 0;
}
