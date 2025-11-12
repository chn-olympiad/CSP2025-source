#include<bits/stdc++.h> 
using namespace std;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s[0];
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
