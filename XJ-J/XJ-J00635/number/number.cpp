#include<bits/stdc++.h>
using namespace std;
int main(){
	//froten("number.in" , r);
	//froten("number.out" , w);
	string s;
	cin >> s;
	int maxn = -1e9;
	int b = s.size();
	for(int  i = 0;i < b; ++i){
		if((s[i] > 'A' && s[i] < 'Z')||(s[i] > 'a' && s[i] < 'z')){
			continue;
		}else{
			if(s[i] > maxn){
				maxn = s[i]-48;
				cout << maxn;
			}
		}
	}
	return 0;
}
