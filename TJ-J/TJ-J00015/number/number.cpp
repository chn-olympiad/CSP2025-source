#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	long long a[1000010],q=n.size();
	int j=0;
	for(int i=0;i<q;i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[j]=n[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	if(a[0]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
