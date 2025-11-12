#include <bits/stdc++.h>
using namespace std;
char a[1000005] , b[1000005];
bool cmp(char s , char t)
{
    return s > t;
}
int main()
{
    freopen("number.in" ,"r" , stdin);
    freopen("number.out" , "w" , stdout);
    memset(a , -1 , sizeof(a));
    cin >> a;
    int j = 0;
    for(int i = 0 ; i < strlen(a) ; i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            b[++j] = a[i];
        }
    }
    sort(b + 1 , b + j + 1 , cmp);
    for(int i = 1 ; i <= j ; i++)
    {
        cout << b[i];
    }
    return 0;
}
