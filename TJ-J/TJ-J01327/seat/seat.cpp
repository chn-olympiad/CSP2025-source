#include <iostream>
using namespace std;
int main()
freopen("seat.in",'r',in);
freopen("seat.out",'w',out);
{
	int a[100][100];
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    sum=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)

        {
            if(a[i][j+1]>a[i][j])
            {
                swap(a[i][j],a[i][j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)

        {
            if(sum==a[i][j])
            {
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
