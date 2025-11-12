#include<bits/stdc++.h>//hujunqin
using namespace std;
int shuzi[10000];
int j=0;
int pd(){
int max=0;
	for(int i=0;i<j;i++){
		if(shuzi[i]>=max) max=shuzi[i];
	}
	for(int i=0;i<j;i++){
		if(shuzi[i]==max) shuzi[i]=0;
	}
	return max;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			shuzi[j++]=s[i]-'0';
		}
	}
	for(int i=0;i<j;i++){
		cout<<pd();
	}
	return 0;
}
