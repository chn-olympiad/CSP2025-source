#include<bits/stdc++.h>
using namespace std;
int a[1000010],ni;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++ni]=s[i]-'0';
	sort(a+1,a+1+ni);
	for(int i=ni;i>=1;i--)cout<<a[i];
}
