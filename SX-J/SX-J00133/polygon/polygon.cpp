#include<bits/stdc++.h>
using namespace std;
int n,k,ma;
int cmy[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)
	{
      cin>>cmy[i];
      k+=cmy[i];
      ma=max(ma,cmy[i]);
	}

    if(n<=2) cout<<0;
    else
    {
      if(k>2*ma) cout<<1;
      else cout<<0;
	}
	return 0;
}

