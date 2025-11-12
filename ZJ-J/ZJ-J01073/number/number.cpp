#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,i;
int a[10];
char ch;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch) s+=ch;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[(s[i]-48)]++;
	}
	for(i=9;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++) printf("%d",i);
		}
	}
	return 0;
}
