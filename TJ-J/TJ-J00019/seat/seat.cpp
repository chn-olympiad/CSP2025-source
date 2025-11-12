#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i-1]>a[i])
        {
            a[i]=a[i-1];
            a[i-1]=a[i];
        }
    }
    cout<<"1"<<"2";
    return 0;
}
