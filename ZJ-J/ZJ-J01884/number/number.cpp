#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ss+=s[i];
		}
	}
	sort(ss.begin(),ss.end(),cmp);
	cout<<ss;	
	return 0;
} 
