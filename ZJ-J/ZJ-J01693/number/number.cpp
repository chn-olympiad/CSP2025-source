#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N],tot;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') num[++tot]=(int)(s[i]-'0');
	}
	sort(num+1,num+tot+1);
	for(int i=tot;i>=1;i--)	cout<<num[i];
return 0;
}
