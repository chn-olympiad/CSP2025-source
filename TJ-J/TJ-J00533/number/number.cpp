#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> digit;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(0<=s[i]-'0'&&9>=s[i]-'0')digit.push_back(s[i]-'0');
	}
	sort(digit.begin(),digit.end(),greater<int>());
	for(int i=0;i<digit.size();i++){
		cout<<digit[i];
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
