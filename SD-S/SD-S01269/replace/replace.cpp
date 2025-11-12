#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
const int N=2e5+10;
int n,m,k;
string ss1[N],ss2[N];
unordered_map<string,string> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>ss1[i]>>ss2[i];
		mp[ss1[i]]=ss2[i];
	}
	while(k--)
	{
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(mp[s1]==s2) cnt++;
		int l=s1.size();
		cout<<cnt<<"\n";
	}
	return 0;
} 
