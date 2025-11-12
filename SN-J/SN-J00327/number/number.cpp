#include<bits/stdc++.h>
using namespace std;
string a[1000010];
int main(){
	//freopen(' .in','r',stdin);
	//freopen(' .out','w',stdout);
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			cout<<s[i];
		}else{
			break;
		}
	}
	return 0;
}
 
