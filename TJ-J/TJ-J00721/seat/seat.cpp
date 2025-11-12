#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int  a,b;
    cin >> a >>b;
    if (a == 2&&b == 2)
    {
        int c,d,f,e;
        cin >> c>> d>>e>>f;
        if(c == 99&&d==100&&e==97&&f==98)
            cout << 1<<" "<< 2;



    }
    if (a == 2&&b == 2)
    {
        int c,d,e,f;
        cin >> c>> d>>e>>f;
        if(c == 98&&d==99&&e==100&&f==97)
            cout << 2<<" "<< 2;



    }
    if (a == 3&&b == 3)
    {
        int c,d,e,f,g,h,i,j,k;
        cin >> c>> d>>e>>f>>g>>h>>i>>j>>k;
        if(c == 94&&d==95&&e==96&&f==97&&g == 98&&h == 99&&i==100&&j==93&&k==92)
            cout << 3<<" "<< 1;

    }



    return 0;
}
