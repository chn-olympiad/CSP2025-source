#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    cin>>r;
    int c[m*n];
    c[-1]=r;
    for(int i=0;i<m*n-1;i++)
    {
        cin>>c[i];
    }
    for(int a=0;a<m*n;a++)
    {
        for(int j=0;j<m*n-1;j++)
        {
            if(c[j]<c[j+1])
            {
                swap(c[j],c[j+1]);
            }
        }

    }
    for(int k=0;k<m*n;k++)
    {
        if(c[k]==r)
        {
            cout<<(k+1)/n<<' '<<(k+1)%n;
        }

    }
    return 0;
}
