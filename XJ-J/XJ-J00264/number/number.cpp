#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e7;
string s;
int a[N]; 
int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	int bnt=0;
	cin>>s;
	s.length();
	cnt=s.length();
	for(int i=0;i<=cnt-1;i++){
		a[i]=11;
	}
    for(int i=0;i<=cnt-1;i++){
		if(s[i]==49) a[i]=1;
		if(s[i]==50) a[i]=2;
	    if(s[i]==51) a[i]=3;
		if(s[i]==52) a[i]=4;
		if(s[i]==53) a[i]=5;
		if(s[i]==54) a[i]=6;
		if(s[i]==55) a[i]=7;
		if(s[i]==56) a[i]=8;
		if(s[i]==57) a[i]=9;
		if(s[i]==48) a[i]=0;
						
	}
	for(int i=0;i<=cnt-1;i++){
		if(a[i]==11) bnt++;
	}

	for(int i=0;i<=cnt-1;i++){
		if(a[i]==1) b[i]=1;
		if(a[i]==2) b[i]=2;
	    if(a[i]==3) b[i]=3;
		if(a[i]==4) b[i]=4;
		if(a[i]==5) b[i]=5;
		if(a[i]==6) b[i]=6;
		if(a[i]==7) b[i]=7;
		if(a[i]==8) b[i]=8;
		if(a[i]==9) b[i]=9;
		if(a[i]==0) b[i]=0;				
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=bnt;i--){
		cout<<b[i];
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
