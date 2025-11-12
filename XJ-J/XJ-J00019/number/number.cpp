#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int b[15];
int main(){
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	for(int i=0;i<=1000000;i++){
		if(a[i]=='0' )b[0]++;
		if(a[i]=='1' )b[1]++;
		if(a[i]=='2' )b[2]++;
		if(a[i]=='3' )b[3]++;
		if(a[i]=='4' )b[4]++;
		if(a[i]=='5' )b[5]++;
		if(a[i]=='6' )b[6]++;
		if(a[i]=='7' )b[7]++;
		if(a[i]=='8' )b[8]++;
		if(a[i]=='9' )b[9]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>0;j--){
			if(i==0)s+='0';
			if(i==1)s+='1';
			if(i==2)s+='2';
			if(i==3)s+='3';
			if(i==4)s+='4';
			if(i==5)s+='5';
			if(i==6)s+='6';
			if(i==7)s+='7';
			if(i==8)s+='8';
			if(i==9)s+='9';
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	
	return 0;	
} 
