#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
int a[9999999],t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-'0';
	sort(a+1,a+1+t);
	for(int i=t;i>0;i--)cout<<a[i];
	return 0;
}
