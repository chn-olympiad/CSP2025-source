#include<bits/stdc++.h>
using namespace std;
long long a,b,c[10010][10010],z10[10010],mx[10010],z20[10010],z30[10010],zd,h1,h2,h3,zg,mi=100000000000000000,lj,p=1,o=1,u=1,z1[10010],z2[10010],z3[10010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>a;
    for(int i=1; i<=a; i++)
    {
    	long long ma[100][10100]{0};
        cin>>b;
        h1=0;
        h2=0;
        h3=0;
        for(int j=1; j<=b; j++)
        {
            for(int f=1; f<=3; f++)
            {
                cin>>c[j][f];
                z10[j]=c[j][1];
                z20[j]=c[j][2];
                z30[j]=c[j][3];
            }
            if(z10[j]>mx[j])
            {
                if(z20[j]>mx[j])
                {
                    if(z30[j]>mx[j])
                    {
                        ma[3][u]=z30[j];
                        h3++;
                        z3[u]=j;
                        u++;
                    }
                    else
                    {
                        ma[2][o]=z20[j];
                        h2++;
                        z2[o]=j;
                        o++;
                    }

                }
                else
                {
                    ma[1][p]=z10[j];
                    h1++;
                    z1[p]=j;
                    p++;
                }

            }


        }
        if(h1<=b/2&&h2<=b/2)
        {
            if(h3<=b/2)
            {
                for(int j=1; j<=3; j++)
                {
                    for(int r=1; r<=b; r++)
                    {
                        if(ma[j][r]!=0)
                        {
                            zg=zg+ma[j][r];
                        }
                        else
                            break;
                    }
                }
            }

            cout<<zg;
            return 0;
        }
        else
            while(h1>b/2||h2>b/2||h3>b/2)
            {
                if(h1>b/2)
                {
                    for(int j=1; j<=h1; j++)
                    {
                        if(ma[1][j]<mi)
                        {
                            mi=z1[j];
                            lj=j;
                        }
                    }
                    if(z20[mi]>z30[mi])
                    {
                        ma[1][lj]=z20[z1[lj]];

                    }
                    else
                        ma[1][lj]=z30[z1[lj]];
                    z10[z1[lj]]=0;
                    h1--;
                }
                mi=100000000000000000;
                if(h2>b/2)
                {
                    for(int j=1; j<=h2; j++)
                    {
                        if(ma[2][j]<mi)
                        {
                            mi=z2[j];
                            lj=j;
                        }
                    }
                    if(z10[mi]>z30[mi])
                    {
                        ma[2][lj]=z10[z2[lj]];
                    }
                    else
                        ma[2][lj]=z30[z2[lj]];
                    z20[z2[lj]]=0;
                    h2--;
                }
                mi=100000000000000000;
                if(h3>b/2)
                {
                    for(int j=1; j<=h3; j++)
                    {
                        if(ma[3][j]<mi)
                        {
                            mi=z3[j];
                            lj=j;
                        }
                    }
                    if(z10[mi]>z20[mi])
                    {
                        ma[3][lj]=z10[z3[lj]];
                    }
                    else
                        ma[3][lj]=z20[z3[lj]];
                    h2--;
                    z30[z3[lj]]=0;
                }
                mi=100000000000000000;
            }
        for(int j=1; j<=3; j++)
        {
            for(int r=1; r<=b; r++)
            {
                if(ma[j][r]!=0)
                {
                    zg=zg+ma[j][r];
                }
                else
                    break;
            }
        }
        cout<<zg;
        return 0;
    }
    return 0;
}