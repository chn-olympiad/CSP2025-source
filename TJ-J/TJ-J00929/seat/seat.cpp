#include<bits/stdc++.h>
using namespace std;
int c ,r,t,obj;
int a[1807];


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>c>>r;
    for(auto i=1;i<=c*r;i++)
    {

        cin>>t;
        a[t]=1;
        if(i==1)  obj=t;


    }
    int x=1,y=1;
    for(auto i=1008;i>=1;i--)
    //x c为行 y r为 列
        if(a[i]==1)
        {
        if(i==obj)
        {
            cout <<x<< " "<<y;
            break;
        }


        if(y%2==1)
        {
            if(x==c) y++;
            else
            {
                x++;
            }

        }
        else
        {
            if(x==1) y++;
            else
            {
                x--;
            }

        }
        }


    fclose(stdin);
    fclose(stdout);
    return 0;
}























































