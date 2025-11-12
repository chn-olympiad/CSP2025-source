#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a[100010],t=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t+1]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
