#include<bits/stdc++.h>
using namespace std;
long long b[10005],s=1;
bool c(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[s]=a[i]-'0';
//			cout<<b[s]<<endl;
			s++;
		}
	}
	sort(b+1,b+s+1,c);
	if(b[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<s;i++)
	{
		cout<<b[i];
	}
	return 0;
}