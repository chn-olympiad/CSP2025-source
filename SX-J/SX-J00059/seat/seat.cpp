#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cjr,pmr;
    cin>>n>>m;
    int j=n*m;
    vector<int> v;
    for(int i=0;i<j;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cjr=v[0];
	sort(v.begin(),v.end());
 	for(int i=0;i<j;i++)
	{
 		cout<<v[i]<<endl;
	}
	for(int i=0;i<j;i++)
	{
		if(v[i]==cjr)
		{
			pmr=j-i;
		}
	}
	int y=pmr/n;
	if(pmr<=n)
 	{
 		cout<<1<<" "<<pmr;
	}
	else
	{
  		if(pmr%n==0)
		{
			cout<<y<<" ";
			if(y%2==0) cout<<1;
			else cout<<n;
		}
		else
		{
			cout<<y+1<<" ";
			if(y%2==0) cout<<pmr%n;
			else cout<<n+1-pmr%n;
		}
	}
	return 0;
}
