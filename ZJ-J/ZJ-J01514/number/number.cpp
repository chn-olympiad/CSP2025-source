#include<bits/stdc++.h>
using namespace std;
#define int long long
int i,a[1000010],n;
string s;
bool is_num(char c){
	return c>='0'&&c<='9';
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(i=0;i<s.size();i++)
		if(is_num(s[i]))
			a[++n]=s[i]-'0';
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
		cout<<a[i];
}