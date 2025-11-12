//T1:8:53 PASS ´óÑùÀý
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> ans;
int cmp(int x,int y) {
	return x>y;
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			int num=s[i]-'0';
			ans.push_back(num);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i];
	}
	return 0;
}
