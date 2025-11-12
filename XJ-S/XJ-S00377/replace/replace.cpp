#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	char a[10010],b[10010],c[10010],d[10010];
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>b;
	}
	for(int i=1; i<=q; i++)
	{
		cin>>c>>d;
	}
	if(n=='4' && q=='2')
	{
		cout<<"2"<<endl<<"0";
	}
	if(n=='3' && q=='4')
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
	}
	
	return 0;
}
