#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;cin>>s;
	long long digit[10]={0};
	for(int i=0;i<=s.size();++i){
		char c=s[i];
		if('0'<=c<='9')
			++digit[c-'0'];
	}
	for(int i=9;i>=0;--i){
		if(digit[i]==0) continue;
		for(int j=digit[i];j>0;--j){
			ans.push_back(i+'0');
			//cout<<digit[i]<<' ';
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
