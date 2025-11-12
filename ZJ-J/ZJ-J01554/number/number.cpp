#include<bits/stdc++.h>
using namespace std;
int a[1000005],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) a[++len]=s[i]-48;
	}
	sort(a+1,a+1+len,greater<int>());
	for(int i=1;i<=len;i++) cout<<a[i];
	return 0;
}
