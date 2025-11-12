//SN-J00460  把小煜  西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
//#define int unsigned long long
using namespace std;
string s;
vector<int>ans;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0' && s[i]<='9') ans.push_back(s[i]-'0');
	sort(ans.begin(),ans.end(),cmp);
	for(int i: ans) cout<<i;
	return 0;
}
