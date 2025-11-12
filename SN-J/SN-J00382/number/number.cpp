#include<bits/stdc++.h>
using namespace std;
int a[1000010],w=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			w++;
		}
	}
	sort(a,a+s.length(),cmp);
	for(int i=0;i<w;i++){
		cout<<a[i];
	}
	return 0;
}
