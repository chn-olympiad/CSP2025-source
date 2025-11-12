#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int shuzi[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			shuzi[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=shuzi[i];j++){
			cout<<i;
		}
	}
	return 0;
}
