#include<bits/stdc++.h>
using namespace std ;
long long k,a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m>>st;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]==st)
        {
            ps=i;
            break;
		}
	}
	int p=ps/n;
	ps%=n;
	x=p+1;
	if(p%2==0)y=n-ps+1;
    else y=ps;
    cout<<y<<x;
	return 0;
}
