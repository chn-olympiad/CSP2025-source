/*
RRRRRRRR    PPPPPPPP                          
RR      RR  PP      PP      ++          ++    
RR      RR  PP      PP      ++          ++    
RRRRRRRR    PPPPPPPP    ++++++++++  ++++++++++
RR  RR      PP              ++          ++    
RR    RR    PP              ++          ++    
RR      RR  PP                                
*/
#include<bits/stdc++.h>
using namespace std;

string s; 
int numbers[10];

int main(){
	ifstream cin("number.in");
	ofstream cout("number.out");
	cin>>s;
	for(int i = 0;i < s.length();i++){
		if('0' <= s[i] && s[i] <= '9'){
			numbers[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= numbers[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
