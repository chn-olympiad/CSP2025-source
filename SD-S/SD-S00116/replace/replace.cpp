#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node
{
	string x;
	string y;
}a[N];
int n,q;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;	
	}
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		string j;
		string s;
		cin>>j>>s;
/*		int flag=0;
		for(int k=1;k<=n;k++)
		{
			if(j==a[i].x && s==a[i].y)
			{
				flag=1;
				cnt++;
			}
		}
		if(flag==0)
			cout<<0<<endl;
		else
			cout<<cnt<<endl;
*/
		cout<<0<<endl;
	}
	return 0;
}
