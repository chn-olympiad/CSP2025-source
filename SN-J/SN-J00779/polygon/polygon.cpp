#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
    int n,num=0;
    cin>>n;
    int a[10005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            for(int x=3;x<=n;x++)
            {
                if(a[i]+a[j]>a[x])
                {
                    if(a[i]+a[x]>a[j])
                    {
                        if(a[j]+a[x]>a[i])
                        {
                            num++;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            for(int x=3;x<=n;x++)
            {
                for(int y=4;y<=n;y++)
                {
                    if(a[i]+a[j]+a[y]>a[x])
                    {
                        if(a[i]+a[x]+a[y]>a[j])
                        {
                            if(a[j]+a[x]+a[y]>a[i])
                            {
                                if(a[i]+a[j]+a[x]>a[y])
                                {
                                    num++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<num;
	return 0;
}
