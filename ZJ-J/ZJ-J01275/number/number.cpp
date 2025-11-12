#include<bits/stdc++.h>
using namespace std;

string s,c;
long a[100];

int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	
	cin>>s;
	for(long i=0;i<s.size();i++){
		char b=s[i];
		if(b>='0'&&b<='9'){
			a[b-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			c+='0'+i;
		}
	}
	
	cout<<c;
	
	return 0;
}
