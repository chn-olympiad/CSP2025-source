#includ <bit/stdc++.h>
using namespace std;
int a[200],n,m,d,ans;
main()
{
	freopen("saet.in","r",stdin);
	freopen("saet.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	d = a[1];
	for(int i = 1;i <= n*m;i++)
	{
		for(int j = 1;j <= n*m;j++)
    	{
		    if(a[i]<a[i+1])
		    {
		    	int b = a[i];
		    	a[i] = a[i+1];
		    	a[i+1] = b;
			}
    	}
	}
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] != d)
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	ans++;
	coyt << (ans-ans%m)/m+1 << " ";
	if(((ans-ans%m)/m+1)%2==0)
	{
		cout << n-ans%m;
	}
	else
	{
		cout << ans%m;
	}
	return 0; 
}
