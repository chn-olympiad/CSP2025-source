//SN-J00199  吴禹泽  陕西延安中学
#include<iostream>
#include<string>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

string s;
int t[100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	fastio;
	
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9'){
			t[s[i]-'0'] ++;
		}
	}
	
	for(int i=9; i>=0; i--){
		while(t[i]){
			cout<<i;
			t[i] --;
		}
	}
	
	return 0;
} 
