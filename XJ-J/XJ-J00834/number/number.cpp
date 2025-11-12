#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

char str[N];
int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int n=strlen(str),sum=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			a[++sum]=str[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
