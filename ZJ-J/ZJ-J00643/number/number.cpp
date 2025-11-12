#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],i,n,ans;string s;
bool cmp(int q,int h){
	return q>h;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	for(i=0;i<s.size();i++)
		if(isdigit(s[i])) n++,a[n]=s[i]-48;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++) cout<<a[i];
	return 0;
}
