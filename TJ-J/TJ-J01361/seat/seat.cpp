#include <bits/stdc++.h>
using namespace std;

int a[111];

//start: 9:10
//finished: 9:25
//bi decode jian dan
//test finished: 9:29

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+k+1);
    int b=1;
    while(a[k-b+1]>r) b++;
    //cout<<b;
    int col,row;
    col=((b-1)/n)+1;
    if(col%2==1) row=((b-1)%n)+1;
    else row=m-((b-1)%n);
    printf("%d %d",col,row);

}
