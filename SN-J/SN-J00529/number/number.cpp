#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool gg(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	string s;
	int b=0;
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' &&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b,gg);
	for (int i=0;i<b;i++){
		if (a[0] == 0){
			cout<<0;
			break;
		}
		cout<<a[i];
	}
	return 0;
}
