#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ans="";
	for(int i=0;i<(int)s.size();i++){
		int now=s[i];
		if(now>='0'&&now<='9'){
			ans+=now;
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
}
