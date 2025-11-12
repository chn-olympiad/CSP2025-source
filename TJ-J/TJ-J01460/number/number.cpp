#include<bits/stdc++.h>
using namespace std;
bool pd(char x){
	if(x>=48&&x<=57){
		return false;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(pd(s[i])){
			s.erase(i,1);
			i--;
		}
	}
	int a[s.size()+5];
	for(int i=0;i<=s.size();i++){
		a[i]=s[i]-'0';
	}
	sort(a,a+s.size()+1);
	for(int i=s.size();i>=1;i--){
		cout<<a[i];
	}
return 0;
} 
