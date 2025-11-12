#include<bits/stdc++.h>
using namespace std;
long long a[1000009],i,s=0,z;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n,m;
	cin>>n;
	for(i=0;i<n.size();i++)
	{
		if(n[i]>='0' and n[i]<='9')
		{
			a[i]=n[i]-'0';
			s++;
		}
	}
	sort(a,a+n.size());
	z=a[n.size()-s];
	for(i=n.size()-1;i>n.size()-s ;i--)
	{
		m=m+(char)(a[i]+'0');
	}
	cout<<m<<z;
}