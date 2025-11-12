#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	string type;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len = s.length();
	for(int i = 0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			type+=s[i];
		}
	}
	sort(type.begin(),type.end());
	int cnt = type.length();
	if(cnt==0||type[cnt-1]=='0'){
		cout<<0<<endl;
		return 0;
	}
	for(int i = cnt-1;i>=0;i--){
		cout<<type[i];
	}
	return 0;
}
