#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[11451];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) t[s[i]]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=t[i+'0'];j++) cout<<i;
	return 0;
}
