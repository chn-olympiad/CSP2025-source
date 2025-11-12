#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10010];
	cin>>a;
	int len=strlen(a);
	long long int b[250099],x=1;
	for(int i=0; i<len; i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[x]=a[i]-'0';
			x++;
		}
	}
	sort(b+1,b+x+1);
	for(int i=x; i>1; i--)
	{
		cout<<b[i];
	}
	
	return 0;
}
