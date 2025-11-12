
#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=10000;
string  a[maxn];
bool b[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;
	int len=s.length();
	if(s=="1"){
		cout<<1;
		return 0;
	}
	if(s=="2"){
		cout<<2;
		return 0;
	}
	if(s=="3"){
		cout<<3;
		return 0;
	}
	if(s=="4"){
		cout<<4;
		return 0;
	}
	if(s=="5"){
		cout<<5;
		return 0;
	}
	if(s=="6"){
		cout<<6;
		return 0;
	}
	if(s=="7"){
		cout<<7;
		return 0;
	}
	if(s=="8"){
		cout<<8;
		return 0;
	}
	if(s=="9"){
		cout<<9;
		return 0;
	}

	for(int i=1;i<=len;i++){
	    if(s=="1")cnt+=1;
		if(s=="2")cnt1+=2;
		if(s=="3")cnt3+=3;
		if(s=="4")cnt4+=4;
		if(s=="5")cnt5+=5;
		if(s=="6")cnt6+=6;
		if(s=="7")cnt7+=7;
		if(s=="8")cnt8+=8;
	    if(s=="9")cnt9+=9;
	}
	cout<<cnt<<cnt1<<cnt2<<cnt3<<cnt4<<cnt5<<cnt6<<cnt7<<cnt8<<cnt9;
	}

	
