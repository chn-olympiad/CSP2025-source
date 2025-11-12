#include <bits/stdc++.h>
using namespace std;
string n;
int a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int x=0,e=0;
	for(int i=0;i<=n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[e]=n[i]-48;
			x++;
			e++;
		}
	}
	sort(a,a+x+1);
	for(int i=x;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
