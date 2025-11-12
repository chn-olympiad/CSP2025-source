#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ans;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end(),[](char a,char b){
		return a>b;
	});
	cout<<ans;
	return 0;
}