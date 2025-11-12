#include<bits/stdc++.h>
using namespace std;
string x;
long long n,i,a[505000],l,h=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	l=x.size();
	x=" "+x;
	for(i=1;i<=l;i++)
	{
		if(int(x[i])<58 && int(x[i])>47)
		{
			h++;
			a[h]=int(x[i])-48;
		}
	}
	sort(a+1,a+h+1,cmp);
	for(i=1;i<=h;i++)
	{
		cout<<a[i];
	}
	return 0;
}