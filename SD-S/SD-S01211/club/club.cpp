#include<bits/stdc++.h>
using namespace std;
int n,cnt;
struct node
{
	int d,f,g;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			int maxn=0;
			cin>>a[i].d>>a[i].f>>a[i].g;
			maxn=max(maxn,a[i].d);
			maxn=max(maxn,a[i].f);
			maxn=max(maxn,a[i].g);
			cnt+=maxn;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
