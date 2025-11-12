#include<bits/stdc++.h> 
using namespace std;
string s;
int b[10000000];
int main(){
	freopen("numbre.in","w",stdin);
	freopen("numbre.out","r",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6 || s[i]==7 || s[i]==8 || s[i]==9){
			b[i]=s[i];
		}
	}
	sort(b,b+s.size());
	for(int i=0;i<s.size();i++){
		cout<<b[i];
	}
	
	
	
	
	return 0;
} 
