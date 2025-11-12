#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[20],c[20],sum;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int r=b[1];
    sort(b,b+(n*m)+1);
    for(int i=n*m;i>=0;i--)
    {
        c[i]=b[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        if(c[i]==r)
        {
            sum=i;
        }

    }
    int cnt=abs(n*m-sum);
    cout<<cnt;
    if(cnt==1)
    {
        cout<<"1"<<" "<<"2";
        return 0;
    }
    if(cnt<m)
    {
        cout<<1<<" "<<cnt;
        return 0;
    }
    else
    {
        if(cnt/m==0)
        {
            cout<<"1"<<" "<<cnt/m;
            return 0;
        }
        else if((cnt-1)/m==0)
        {
            cout<<m<<" "<<cnt/n;

            return 0;
        }
        else
        {
            int l=cnt/m;
            int h=cnt/n;
            cout<<l<<" "<<h+1;
            return 0;
        }
    }
    return 0;
}
