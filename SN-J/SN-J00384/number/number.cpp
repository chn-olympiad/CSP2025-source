//SN-J00384  张溪诺  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,top;
string s;
int a[10000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++top]=s[i]-48;
		}
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

