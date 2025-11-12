#include<bits/stdc++.h>
using namespace std;
string a;
int f[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	int la=a.length(),x=0;
	for(int i=0;i<la;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			x++;
			f[x]=a[i]-'0';
		}
	}
	sort(f+1,f+1+x);
	for(int i=x;i>=1;i--)
		cout<<f[i];
	return 0;
}
