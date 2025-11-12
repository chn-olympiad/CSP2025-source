#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>v[i];
	}
	int x=v[1];
	sort(v.begin(),v.end());
	for(int i=1;i<=n*m;i++)
	{
		if(v[i]==x)
		{
			int y=i,r,c;
			if(y%n==0)
			{
				r=n;
			}
			else r=y%n;
			c=(y-r)/n+1;
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
}
