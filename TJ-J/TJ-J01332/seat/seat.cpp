#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],flg=0,score,it=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    score=a[0];
    sort(a,a+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(flg==0)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[it]==score)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                it++;
            }
            flg=1;
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(a[it]==score)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                it++;
            }
            flg=0;
        }
    }
    return 0;
}
