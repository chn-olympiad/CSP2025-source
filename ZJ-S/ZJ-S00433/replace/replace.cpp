#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1,s2;
}a[200010];
int main()
{
	freopen("replace","r",stdin);
	freopen("replace","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--)
	{
		string q1,q2;
		cin>>q1>>q2;
	}
	return 0;
}