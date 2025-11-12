#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')ans.push_back(s[i]-'0');
	}
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}