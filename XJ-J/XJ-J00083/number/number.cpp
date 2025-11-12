#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if(s[0]=='0'){
		cout << 0;
	}
	if(s[0]=='1'){
		cout << 1;
	}
	if(s[0]=='2'){
		cout << 2;
	}
	if(s[0]=='3'){
		cout << 3;
	}
	if(s[0]=='4'){
		cout << 4;
	}
	if(s[0]=='5'){
		cout << 5;
	}
	if(s[0]=='6'){
		cout << 6;
	}
	if(s[0]=='7'){
		cout << 7;
	}
	if(s[0]=='8'){
		cout << 8;
	}
	if(s[0]=='9'){
		cout << 9;
	}
	/*int n;
	string s1;
	s1="number.in";
	string s;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			s+=s1[i];
		}
	}
	int maxn=-1;
	for(int i=0;i<s.size();i++){
		char b[1000000];
		b[0]=s[i];
		for(int j=1;j<s.size();j++){
			if(j!=i){
				b[j]=s[j];
			}	
		}
		n=sscanf(b,"%d",n);
		maxn=max(maxn,n);
		
	}
	cout << maxn;*/
	return 0;
} 
