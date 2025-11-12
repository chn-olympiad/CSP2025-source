#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	int l1=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l1++;
			a[l1]=s[i]-'0';
		}
	}
	sort(a+1,a+l1+1,greater<int>());
	for(int i=1;i<=l1;i++){
		cout<<a[i];
	}
	return 0;
}
