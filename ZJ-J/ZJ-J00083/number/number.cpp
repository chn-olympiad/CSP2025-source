#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[1000010],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;++i)
	if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
	sort(a+1,a+n+1);
	for(int i=n;i;--i)cout<<a[i];
	return 0;
}
