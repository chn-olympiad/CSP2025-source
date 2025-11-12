//SN-J00649  林靖轩  西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int a[N],tot=0;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' ||
			s[i]=='4' || s[i]=='5' || s[i]=='6' ||
			s[i]=='7' || s[i]=='8' || s[i]=='9' ||
			s[i]=='0')
		tot++,a[tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
		cout<<a[i];
	return 0;
}

