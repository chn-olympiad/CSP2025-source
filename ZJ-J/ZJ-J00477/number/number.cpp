#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	string ans="";
	for(auto x:s){
		if(x>='0'&&x<='9') ans+=x;
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}