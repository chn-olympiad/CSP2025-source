#include<bits/stdc++.h>
using namespace std;
string h;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>h;
	for(long long i=0;i<h.size();i++){
		if(h.find('9')!=-1&&h.find('9')!=string::npos){
			cout<<9;
			h[h.find('9')]='0';
			continue;
		}
		if(h.find('8')!=-1&&h.find('8')!=string::npos){
			cout<<8;
			h[h.find('8')]='0';
			continue;
		}
		if(h.find('7')!=-1&&h.find('7')!=string::npos){
			cout<<7;
			h[h.find('7')]='0';
			continue;
		}
		if(h.find('6')!=-1&&h.find('6')!=string::npos){
			cout<<6;
			h[h.find('6')]='0';
			continue;
		}
		if(h.find('5')!=-1&&h.find('5')!=string::npos){
			cout<<5;
			h[h.find('5')]='0';
			continue;
		}
		if(h.find('4')!=-1&&h.find('4')!=string::npos){
			cout<<4;
			h[h.find('4')]='0';
			continue;
		}
		if(h.find('3')!=-1&&h.find('3')!=string::npos){
			cout<<3;
			h[h.find('3')]='0';
			continue;
		}
		if(h.find('2')!=-1&&h.find('2')!=string::npos){
			cout<<2;
			h[h.find('2')]='0';
			continue;
		}
		if(h.find('1')!=-1&&h.find('1')!=string::npos){
			cout<<1;
			h[h.find('1')]='0';
			continue;
		}
	}
	return 0;
} 
