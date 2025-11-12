//许明宇-SN-J00976-西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
string s="";
char c;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0'&&c<='9'){
			s+=c;
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
