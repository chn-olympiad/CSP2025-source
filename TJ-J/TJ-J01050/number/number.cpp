#include<bits/stdc++.h>
using namespace std;
int main(){
	feropen("number.in","r",stdin);
	feropen("number.out","w",stdout);
	char n[100005];
	cin>>n;
	int x=0,x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,x9=0;
	for(int i=0;i<90000;i++){
		if(n[i]=='0')x++;
		if(n[i]=='1')x1++;
		if(n[i]=='2')x2++;
		if(n[i]=='3')x3++;
		if(n[i]=='4')x4++;
		if(n[i]=='5')x5++;
		if(n[i]=='6')x6++;
		if(n[i]=='7')x7++;
		if(n[i]=='8')x8++;
		if(n[i]=='9')x9++;
	}
	for(int i=0;i<x9;i++){
		cout<<'9';
	}
	for(int i=0;i<x8;i++){
		cout<<'8';
	}
	for(int i=0;i<x7;i++){
		cout<<'7';
	}
	for(int i=0;i<x6;i++){
		cout<<'6';
	}
	for(int i=0;i<x5;i++){
		cout<<'5';
	}
	for(int i=0;i<x4;i++){
		cout<<'4';
	}
	for(int i=0;i<x3;i++){
		cout<<'3';
	}
	for(int i=0;i<x2;i++){
		cout<<'2';
	}
	for(int i=0;i<x1;i++){
		cout<<'1';
	}
	for(int i=0;i<x;i++){
		cout<<'0';
	}
	return 0;
}
