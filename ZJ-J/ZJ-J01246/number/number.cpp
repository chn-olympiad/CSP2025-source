#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<count(s.begin(),s.end(),'9');i++){
		cout<<'9';
	}
	for(int i=0;i<count(s.begin(),s.end(),'8');i++){
		cout<<'8';
	}
	for(int i=0;i<count(s.begin(),s.end(),'7');i++){
		cout<<'7';
	}
	for(int i=0;i<count(s.begin(),s.end(),'6');i++){
		cout<<'6';
	}
	for(int i=0;i<count(s.begin(),s.end(),'5');i++){
		cout<<'5';
	}
	for(int i=0;i<count(s.begin(),s.end(),'4');i++){
		cout<<'4';
	}
	for(int i=0;i<count(s.begin(),s.end(),'3');i++){
		cout<<'3';
	}
	for(int i=0;i<count(s.begin(),s.end(),'2');i++){
		cout<<'2';
	}
	for(int i=0;i<count(s.begin(),s.end(),'1');i++){
		cout<<'1';
	}
	for(int i=0;i<count(s.begin(),s.end(),'0');i++){
		cout<<'0';
	}
	cout<<endl;
	
}
