#include<bits/stdc++.h>
using namespace std;
string s;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'9'<=0) ans[s[i]-'0']++;
	}for(int i=9;i>=0;i--){
		for(int o=0;o<ans[i];o++) cout<<i;
	}
	cout<<endl;
	return 0;
}
