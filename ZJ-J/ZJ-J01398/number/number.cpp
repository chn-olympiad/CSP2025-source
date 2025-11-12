#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string n;
int a[N],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[++t]=n[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

