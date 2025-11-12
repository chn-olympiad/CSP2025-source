#include<bits/stdc++.h>
using namespace std;
int n,m=0,h;
string s;
string t;	    
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			t[m]=s[i];
			m++;
		}	
	}
	for(int i=1;i<s.size();i++){
		for(int i=1;i<s.size();i++){
			if(t[i]>t[i-1]){
				h=t[i];
				t[i]=t[i-1];
				t[i-1]=h;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<t[i];
	}
	return 0;
}
