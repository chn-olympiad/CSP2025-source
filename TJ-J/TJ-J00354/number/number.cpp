#include<bits/stdc++.h>
using namespace std;
map<char,long long> m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			m[s]++;
		}
	}
	for(int i=1;i<=m['9'];i++) cout<<9;
	for(int i=1;i<=m['8'];i++) cout<<8;
	for(int i=1;i<=m['7'];i++) cout<<7;
	for(int i=1;i<=m['6'];i++) cout<<6;
	for(int i=1;i<=m['5'];i++) cout<<5;
	for(int i=1;i<=m['4'];i++) cout<<4;
	for(int i=1;i<=m['3'];i++) cout<<3;
	for(int i=1;i<=m['2'];i++) cout<<2;
	for(int i=1;i<=m['1'];i++) cout<<1;
	for(int i=1;i<=m['0'];i++) cout<<0;
	
	return 0;
} 
