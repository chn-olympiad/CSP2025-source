#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],i,j;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0; i<s.size(); i++)if(s[i]>='0'&&s[i]<='9')a[++j]=s[i]-'0';
	sort(a+1,a+1+j);
	for(i=j; i>=1; i--)cout<<a[i];
}
