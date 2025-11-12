#include<bits/stdc++.h>
using namespace std;
string a;
int b[100000],xb;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<=len-1;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			xb++;
			b[xb]=a[i]-'0';
		}
	}
	sort(b+1,b+xb+1);
	long long int c=0;
	for(int i=xb;i>=1;i--)
	{		
		c+=b[i];
		c*=10;
	}
	cout<<c/10;
 } 
