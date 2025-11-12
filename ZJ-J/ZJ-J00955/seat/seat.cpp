#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n,m,a[105],k,cnt=1,p=0,q=1;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
        cin>>a[i];
    k=a[1];
    for(int i=1;i<=m*n;i++)
        if(k<a[i+1])
            cnt++;
    while(cnt!=0)
    {
        cnt--;
        p++;
        if(p==n+1)
        {
            p=1;
            q++;
        }
    }
    if(q%2==0)
        cout<<q<<" "<<n-p+1<<endl;
    else
        cout<<q<<" "<<p-1<<endl;
    return 0;
}
