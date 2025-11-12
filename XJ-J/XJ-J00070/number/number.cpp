#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long A0=0,A1=0,A2=0,A3=0,A4=0,A5=0,A6=0,A7=0,A8=0,A9=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			A0++;
			
		}else if(s[i]=='1'){
			A1++;
			
		}else if(s[i]=='2'){
			A2++;
			
		}else if(s[i]=='3'){
			A3++;
			
		}else if(s[i]=='4'){
			A4++;
			
		}else if(s[i]=='5'){
			A5++;
			
		}else if(s[i]=='6'){
			A6++;
			
		}else if(s[i]=='7'){
			A7++;
			
		}else if(s[i]=='8'){
			A8++;
			
		}else if(s[i]=='9'){
			A9++;
		
		}
	}for(int i=1;i<=A9;i++){
		cout<<"9";
	}for(int i=1;i<=A8;i++){
		cout<<"8";
	}for(int i=1;i<=A7;i++){
		cout<<"7";
	}for(int i=1;i<=A6;i++){
		cout<<"6";
	}for(int i=1;i<=A5;i++){
		cout<<"5";
	}for(int i=1;i<=A4;i++){
		cout<<"4";
	}for(int i=1;i<=A3;i++){
		cout<<"3";
	}for(int i=1;i<=A2;i++){
		cout<<"2";
	}for(int i=1;i<=A1;i++){
		cout<<"1";
	}for(int i=1;i<=A0;i++){
		cout<<"0";
	}
	return 0;
} 
