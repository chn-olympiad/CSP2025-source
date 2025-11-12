#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ws,i,x=0;
	ws=s.size();
	for(i=0;i<=ws;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++x]=int(s[i]-'0');
		}
	}
	sort(a+1,a+x+1);
	for(i=x;i>=1;i--) cout<<a[i];
	return 0;
}
