#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

string s;
vector<int> ans;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for (char c:s)
	{
		if ('0'<=c && c<='9') ans.push_back(c-'0');
	}
	
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	
	for (int i:ans) cout<<i;
	
 	return 0;
}

