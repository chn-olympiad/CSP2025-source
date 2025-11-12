#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[1000005],zz;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9') a[++zz]=(int)(s[i]-'0');
	}
	sort(a+1,a+zz+1);
	for(int i=zz;i>0;i--) cout<<a[i];
	return 0;
}

