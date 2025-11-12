#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;

int a[N];


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int sum = n*m;
    for(int i=0;i<sum;i++)
    {
        cin >>a[i];
    }
    int res=a[0];
    sort(a,a+sum);
    int tag=1;
    for(int i=sum-1;i>=0;i--)
    {
        if(a[i]==res)
            break;
        tag++;
    }
    int x = (tag-1)/n+1;
    int y =-1;
    if(x%2==0)
        y= n-(tag%n)+1;
    else
        y =(tag-1)%n+1;

    cout <<x<<" "<<y<<endl;
    
    return 0;
}