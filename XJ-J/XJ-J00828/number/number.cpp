#include <iostream>
#include <string>
using namespace std;

string s;
long long h[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	int len = s.size();
	for(int i=0; i<len; i++){
		if(s[i]>='0'&&s[i]<='9'){
			h[s[i]-'0']++;
		}
	} 
	for(int i=9; i>=0; i--){
		while(h[i]--)cout<<i;
	}
	return 0;
} 
