#include <bits/stdc++.h>
using namespace std;
int a[105];
int a2[105];
int n,m,k=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;//[n,m]
    int num=n*m;
    for(int i=1;i<=num;i++)
    {
        cin>>a[i];
    }
    int p=a[1];
    if(p==100)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    sort(a+1,a+num+1);
	for(int i=1;i<=num;i++)
	{
		a2[i]=a[num-i+1];
	}

	while(k<=num)
	{
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(j%2==1)
				{
					if(a2[k]==p)
	            	{
	                	cout<<j<<" "<<i;
	                	return 0;
	            	}
				}
				if(j%2==0)
				{
					if(a2[k]==p)
	            	{
	                	cout<<j<<" "<<n-i+1;
	                	return 0;
	            	}
				}
				k++;
			}}}
    return 0;
}
