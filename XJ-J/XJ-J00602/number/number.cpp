#include<bits/stdc++.h>
using namespace std;
char x;
long long a[1000010],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>x)
	{
		if(x>='0'&&x<='9')
		{
			a[++k]=x-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
