#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    long long z,cnt,y=0,x;
    long long a[1001]= {0};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 && j==0)
            {
                cin>>cnt;
                a[cnt]++;
            }
            else
            {
                cin>>z;
                a[z]++;
            }

        }
    }

    for(int i=100; i>=0; i--)
    {
        if(a[i]==1)
        {
            y++;
            if(i==cnt)
            {
                x=y;
            }
        }
    }

    long long h,l;
    if(x%m==0)
    {
        l=x/m;
        if(l%2==0)
        {
            h=1;
        }
        else
        {
            h=n;
        }
    }
    else
    {
        l=(x/m)+1;
        if(l%2==0)
        {
            h=n-x%n+1;
        }
        else
        {
            h=x%n;
        }
    }

    cout<<l<<" "<<h;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
