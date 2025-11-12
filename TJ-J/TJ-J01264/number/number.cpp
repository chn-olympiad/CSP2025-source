#include<bits/stdc++.h>
using namespace std;
int t=0;
string str;
int ch[1000007];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>str;
	
	for (int i=0;i<str.size();i++){
		if (str[i]<'a'){
			ch[t]=int(str[i]);
			t++;
		}
		
	}
	sort(ch,ch+t);
	for (int i=t-1;i>=0;i--){
		if (ch[i]<97){
			cout<<ch[i]-'0';
		}
	}
	return 0;
} 
