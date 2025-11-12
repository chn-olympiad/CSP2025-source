#include<bits/stdc++.h>
using namespace std;
bool b(int a,int b){
	if(a>b) return 1;
	else return 0;
}int r;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[s.length()];
	for(int i=0;i<=s.length();i++){
		a[i]=0;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[r]=s[i]-'0';
			r++;
		}
	}sort(a,a+s.length(),b);
	for(int i=0;i<r;i++){
		cout<<a[i];
	}
	return 0;
}
