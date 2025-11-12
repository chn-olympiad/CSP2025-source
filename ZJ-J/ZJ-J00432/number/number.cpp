#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],h,l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++h]=s[i]-'0';
	}
	sort(a+1,a+1+h);
	for(int i=h;i>=1;i--)cout<<a[i];
	return 0;
}//#Shang4Shan3Ruo6Shui4
