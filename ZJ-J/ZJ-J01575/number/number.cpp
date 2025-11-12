#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream("number.in");
	ofstream("number.out");
	string s;
	int n[100]={0},g=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			n[g]=s[i]-48;
			g++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<g;j++){
			if(n[j]==i){
				cout<<n[j];
			}
		}
	}
}
