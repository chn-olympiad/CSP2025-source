#include<bits/stdc++.h>
using namespace std;
string s;
string n;
int a[15];
int main(){
	cin>>s;
	for(int i = 0;i<s.length();i++){
		if(((int)(s[i]-'0')<=9)&&((int)(s[i]-'0')>=0)){
			a[(int)(s[i]-'0')]++;
		}
	}
	for (int i = 9;i>=0;i--){
		for (int j = 1;j<=a[i];j++){
			switch(i){
				case 0:n+="0";break;
				case 1:n+="1";break;
				case 2:n+="2";break;
				case 3:n+="3";break;
				case 4:n+="4";break;
				case 5:n+="5";break;
				case 6:n+="6";break;
				case 7:n+="7";break;
				case 8:n+="8";break;
				case 9:n+="9";break;
			}
		}
	}
	cout<<n;
	return 0;
}
