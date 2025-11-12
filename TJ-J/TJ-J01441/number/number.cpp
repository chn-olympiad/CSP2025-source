#include<bits/stdc++.h>
using namespace std;
int a[10001];
string s;
int n=0;
int main(){
	freopen("number.in","t",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){ 
//		if('9'>=s[i]>='0'){
		if(s[i]=='9'){
			cout<<'9';
		}
		else if(s[i]=='8'){
			cout<<'8';
		}
		else if(s[i]=='7'){
			cout<<'7';
		}
		else if(s[i]=='6'){
			cout<<'6';
		}
		else if(s[i]=='5'){
			cout<<'5';
		}
		else if(s[i]=='4'){
			cout<<'4';
		}
		else if(s[i]=='3'){
			cout<<'3';
		}
		else if(s[i]=='2'){
			cout<<'2';
		}
		else if(s[i]=='1'){
			cout<<'1';
		}
		else if(s[i]=='0'){
			cout<<'0';
		}
		else{
			if(s[i-1]=='0'){
				cout<<'0';
			}
			break;
		}
//		}
		if('z'>=s[i]>='a'){
			continue;
		}
	}
	return 0;
}
