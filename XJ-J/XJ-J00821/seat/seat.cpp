#include<bits/stdc++.h>
using namespace std;
int s[105],zuowei[15][15];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s[1];
    int cj=s[1];
    for(int i=2;i<=n*m;i++)
        cin>>s[i];
    sort(s+1,s+1+n*m,cmp);
    int num=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++,num++)
            {
                zuowei[i][j]=s[num];
                if(s[num]==cj)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=m;j>=1;j--,num++)
            {
                zuowei[i][j]=s[num];
                if(s[num]==cj)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
