#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool tmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100];
    for (int i=0;i<n*m;i++)
    {
        cin>>a[i];

    }
    //correct
    int R=a[0];
    //correct
    sort(a,a+(n*m),tmp);
    //correct
    int seat[10][10];
    int cnt=0;
    for (int i=0;i<m;i++)
    {
        if((i+1)%2==0)
        {
            for (int j=n-1;j>=0;j--)
            {
                seat[i][j]=a[cnt];
                cnt++;
            }
        }
        else
        {
            for (int j=0;j<n;j++)
            {
                seat[i][j]=a[cnt];
                cnt++;
            }
        }
    }
    /*for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<seat[i][j]<<' ';
        }
    }*/
    //correct
    int x,y;
    bool is_found=false;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (seat[i][j]==R)
            {
                x=i;
                y=j;
                is_found=true;
                break;
            }
        }
        if (is_found==true)
        {
            break;
        }
    }
    cout<<x+1<<' '<<y+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
