#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char>ans;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			char num=s[i];
			ans.push_back(num);
		}
	}
	for(int i=0;i<s.size();i++){
		char maxn=max(ans[i],ans[i+1]);
		cout<<maxn;
	}
	return 0;
}
