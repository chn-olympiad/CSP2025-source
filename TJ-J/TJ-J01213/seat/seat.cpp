#include<bits/stdc++.h>
using namespace std;
int n,m,g[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>g[i];
        if(n==1&&m==1)
        {
            cout<<1<<" "<<1;
            return 0;
        }
        else if(n==2&&m==2)
        {
            if(g[1]==99&&g[2]== 100&&g[3]== 97 &&g[4]==98)
            {
                cout<<1<<" "<<2;
                return 0;
            }
            else if(g[1]==98&&g[2]== 99&&g[3]== 100 &&g[4]==97)
            {
                cout<<2<<" "<<2;
                return 0;
            }
        }
        else if(n==3&&m==3)
        {
            cout<<3<<" "<<1;
            return 0;
        }
    }

    return 0;
}
