#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0' && s[i]<='9')ans.emplace_back(s[i]-'0');
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;~i;i--)cout<<ans[i];
	return 0;
}