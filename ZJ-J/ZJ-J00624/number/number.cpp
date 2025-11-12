#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;s[i];i++)
	  if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),greater<int>());
	for(auto it:v) cout<<it;
	return 0;
}
