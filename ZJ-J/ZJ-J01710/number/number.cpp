#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string s2;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			s2+=s[i];
		}
	}
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;
	return 0;
}