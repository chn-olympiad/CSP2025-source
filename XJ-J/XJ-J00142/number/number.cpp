#include<bits/stdc++.h>
using namespace std;
string str;
int l,s[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			s[l++]=str[i]-'0';
		}
	}
	sort(s,s+l,cmp);
	for(int i=0;i<l;i++){
		cout<<s[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
