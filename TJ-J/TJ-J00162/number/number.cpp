#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	char c;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		} 
	}for(int i=0;i<s1.length();i++){
		for(int j=0;j<s1.length();j++){
			if(i==j)continue;
			if(s1[i]>=s1[j]){
				c=s1[i];
				s1[i]=s1[j];
				s1[j]=c;
			}
		}
		 
	}
	for(int i=0;i<s1.length();i++){
		cout<<s1[i];
	}
	return 0;
} 
