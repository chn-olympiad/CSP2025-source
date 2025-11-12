#include<bits/stdc++.h>
using namespace std;
int n,q;
string x[100005],y[100005];
string a[100005],b[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]==a[j]&&y[i]==b[j])
			{
				cout<<j<<endl;
				break;
			}
			cout<<0<<endl;
			break;
		}
	}
	return 0;
}
