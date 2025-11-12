#include<bits/stdc++.h>
using namespace std;
int b[1000006];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		b[j++]=a[i]-'0';
	}
	sort(b,b+j,cmp);
	for(int i=0;i<j;i++)
	{
		cout<<b[i];
	}
	return 0;
}
