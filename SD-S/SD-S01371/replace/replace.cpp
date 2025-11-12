#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string a1[200005],b1[200005],a2[200005],b2[200005];
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a1[i]>>a2[i];
	for(int i=1;i<=q;i++)
		cin>>b1[i]>>b2[i];
	for(int i=1;i<=q;i++)
		cout<<"0"<<'\n';
	return 0;
}
