#include<iostream>
#include<algorithm>
using namespace std;
string a;
int b[10005],x=1;
bool cmp(int z,int y)
{
	if(y<z) return z>y;
	else return y<z;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[x]=(a[i]-'0');
			x++;
		}
	}
	sort(b+1,b+1+x,cmp);
	for(int i=1;i<x;i++)
	{
		cout<<b[i];
	}
	return 0;
}
