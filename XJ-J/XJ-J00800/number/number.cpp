#include<bits/stdc++.h>
using namespace std;
const int N=1e6+500;
string s;
int b[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int tot=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			b[++tot]=s[i]-'0';
		}
	}
	sort(b+1,b+1+tot);
	for(int i=tot;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
} 
