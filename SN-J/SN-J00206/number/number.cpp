#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i+1]<s[i]){
				cout<<s[i];
			}
			else{
				int temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
				cout<<s[i];
			}
		}
	}
	
	return 0;
		
}
	
