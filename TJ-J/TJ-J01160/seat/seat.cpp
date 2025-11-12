#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    int s[n*m+1];
    int s1;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    s1=s[1];
    for(int i=0;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(s[i]<s[j])
            {
                swap(s[i],s[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==s1)
        {
            if((i/n)%2==0)
            {
                r=i%n;
            }
            else
            {
                if(i==n)
                {
                    r=n;
                }
                else
                {
                    r=n-(i%n)+1;
                }
            }
            if(i%2==0)
            {
                c=i/n;
            }
            else
            {
                c=i/n+1;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
