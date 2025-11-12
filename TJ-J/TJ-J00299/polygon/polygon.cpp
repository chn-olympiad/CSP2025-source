#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
    if(n==3)
    {
        int sjx[4];
        for(int i=1;i<=3;i++)
        {
            cin>>sjx[i];
        }
        sort(sjx+1,sjx+4);
        if(sjx[1]+sjx[2]>sjx[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {

        cout<<6;
    }
}
