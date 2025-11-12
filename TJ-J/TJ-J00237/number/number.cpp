#include <bits/stdc++.h>
using namespace std;
int x;
char n[1001]; 
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[i]=s[i];
			x++;
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<i;j++){
			if(n[i]>n[j]){
				swap(n[i],n[j]);
			}
		}
	}
	for(int i=0;i<x;i++){
		printf("%c",n[i]);
	}
	return 0;
} 
