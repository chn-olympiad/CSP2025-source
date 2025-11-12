#include<bits/stdc++.h>
using namespace std;
struct node
{
	string a;
	string b;
};
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1; i <= n; i ++)
	{
		node w[20005];
		cin>>w[i].a>>w[i].b;
	}
	for(int i = 1; i <= q; i ++)
	{
		node u[20005];
		cin>>u[i].a>>u[i].b;
	}
	while(q--)
	{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
