#include<bits/stdc++.h>
using namespace std;
int a[4500][4500];
int s[100001];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, b;
    cin >> n >> m;
    for(int i = 0;i <= (n-1)*(m-1);i++)
    {
        cin >> s[i];
        b = s[0];
    }
    int x;
    for(int i = 0;i < n*m;i++)
    {
        if(s[i]<s[i+1])
        {
            x = s[i];
            s[i] = s[i+1];
            s[i+1] = x;
        }

    }
    for(int i = n;i > 0;i--)
    {
        for(int j = m;j > 0;j--)
        {
            if(j%2==0)
            {
                a[i][j] = s[i];
            }
            else{
                for(int i = 0;i <= n;i++)
                {
                    for(int j = 0;j <= m;j++)
                    {
                        if(j%2==1)
                        {
                            a[i][j] = s[i];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(b==a[i][j])
            {
                cout << b << endl;
                cout << i+1 << " " << j+1;
                break;
            }
        }
    }
    return 0;
}
