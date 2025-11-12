#include <iostream>
using namespace std;
int main()
int n,m,a[],s[],k;
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        s[i]=a[i];
    }
    for(int i=1;i<=s.size();i++)
    {
        if(s[i+1]<s[i])
        {
            s[i]=k;
            s[i+1]=s[i];
            k=s[i+1];
        }
    }
    if()
}
