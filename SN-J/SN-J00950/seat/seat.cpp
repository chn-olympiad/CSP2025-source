#include<bits/stdc++.h>
using namespace std;
int n,m,s[15][15];
vector <int>v;
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	const int q=n*m;
	for(int i=1;i<=q;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	int e=v[1];
	sort(v.begin(),v.end()+1);
	for(int i=v.size();i>=1;i--)
	{
		if(v[i]==e)
		{
			int c=i/m;
			int r=i%n;
			cout<<c<<' '<<r;
			break;
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if()
//			
//		}
//	}
	
	
	return 0;
}
