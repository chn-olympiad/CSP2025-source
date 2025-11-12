#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],len=0;
char cmp(char x,char b){
	return x>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(isdigit(s[i])){
			len++;
			a[len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
