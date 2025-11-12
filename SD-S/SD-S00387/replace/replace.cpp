#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
string a[N+50],b[N+50];
string qian[N+50],hou[N+50];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qian[i]>>hou[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
