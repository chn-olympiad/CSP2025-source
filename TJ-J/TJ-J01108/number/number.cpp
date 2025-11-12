#include<iostream>
#include<cstdlib>
#include<string.h>
#include<string>
using namespace std;
const int MAXN = 1e6;
int na[10];
string s;

void pre(){
	memset(na,0,sizeof(na));
	for(int i=0;i<s.length();i++){
		int char_num = s[i]-'0';
		if(char_num>=0&&char_num<=9){
			na[char_num]++;
		}
	}
}

void get(){
	for(int i=9;i>=0;i--){
		for(int j=0;j<na[i];j++){
			cout << i;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	pre();get();
	return 0;
} 
