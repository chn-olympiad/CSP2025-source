#include<bits/stdc++.h>
using namespace std;
string s;int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++)if(isdigit(s[i]))num[s[i]-48]++;
	for(int i=9;i>=0;i--){
		cout<<string(num[i],i+48);
	}
	return 0;
}
