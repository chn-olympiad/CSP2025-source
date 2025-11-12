#include <bits/stdc++.h>
using namespace std;
long long n,k,x,ans;
bool flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if (k)
	{
		for (int i=1; i<=n; i++)
		{
			cin>>x;
			if (x==1) ans++;
		}
    }
    else
    {
    	for (int i=1; i<=n; i++)
    	{
    		cin>>x;
    		if (x==0 or flag) ans++,flag=0;
    		else flag=1;
		}
	}
	cout<<ans;
	return 0;
}
