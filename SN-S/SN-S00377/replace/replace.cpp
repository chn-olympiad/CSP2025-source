#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> p[200001],q[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		p[i]={a,b};
	}
	for(int i=0;i<q;i++)
	{
		string a,b;
		cin>>a>>b;
		q[i]={a,b};
	}
	cout<<rand();
	return 0;
}

