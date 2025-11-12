#include<bits/stdc++.h>
using namespace std;
string s;
int a[1007],s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s1=s.size();
	for(int i=0;i<s1;++i){
		if(s[i]>='0' && s[i]<='9'){
			a[++a[0]]=s[i]-'0';
		}
	}
	sort(a+1,a+1+a[0]);
	for(int i=a[0];i>0;--i){
		cout<<a[i];
	}
	return 0;
}
