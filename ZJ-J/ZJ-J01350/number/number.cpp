#include <bits/stdc++.h>
using namespace std;
int n,i,a[1000010],t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for (i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-48;
	sort(a+1,a+t+1);
	for (i=t;i>=1;i--)
		cout<<a[i];
}
