#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string q;
    cin>>q;
    int e=q.length();
    int w[e+1];
    w[0]=0;
    for (int i=0;i<e;i++)
    {
        if (q[i]>='0' && q[i]<='9')
        {
            w[i+1]=q[i]-'0';
        }
    }
    sort(w+1,w+e+2);
    for (int i=e+1;i>=1;i--)
    {
        cout<<w[i];
    }
}

