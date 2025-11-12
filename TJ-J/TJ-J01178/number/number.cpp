#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
string s1="";
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	cout<<s1;
	return 0;
}
