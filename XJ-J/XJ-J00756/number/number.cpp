#include<bits/stdc++.h>
using namespace std;
long long a[1000005]={0};
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i,j,ans,s,t;
	cin>>s;
	i=1;
	while(s!=0)
	{
		a[i]=s%10;
		s=s/10;
		i++;
	}
	sort(a+1,a+i);
	while(i--)
	{
		if(i>0)
		{
			cout<<a[i];
		}
	}
	return 0;
}
