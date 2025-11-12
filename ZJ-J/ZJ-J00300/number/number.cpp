#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n;
bool cmp(int a,int b) {
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) 
		if(isdigit(s[i])) a[++n] = s[i]-'0';
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i];
	
	return 0;
}
