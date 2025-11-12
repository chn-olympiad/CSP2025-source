#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			c++;
			a[c]=s[i]-48;
		}
	}
	sort(a+1,a+1+c);
	for(int i=c;i>0;i--){
		if(a[c]==0){
			cout<<"0";
			return 0;
		} 
		cout<<a[i];
	}
}
