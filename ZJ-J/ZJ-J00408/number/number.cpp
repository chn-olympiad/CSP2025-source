#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[15];
string s;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9; i>=0; i--)
		for(int j=1; j<=a[i]; j++)
			cout<<i;
	return 0;
}
//csprp++;