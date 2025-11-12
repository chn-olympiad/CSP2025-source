#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int n=str.size();
	str=" "+str;
	vector<char>s;
	for(int i=1;i<=n;i++){
		char ch=str[i];
		if(ch>='0'&&ch<='9')s.push_back(ch);
	}
	sort(s.begin(),s.end(),greater<char>());
	for(char i:s)cout<<i;
	return 0;
}
