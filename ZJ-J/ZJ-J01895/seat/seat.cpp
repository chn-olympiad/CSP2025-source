#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int num,id;
}a[105];
bool cmp(node x,node y)
{
    return x.num>y.num;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        int x;
        cin>>x;
        a[i].num=x;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int pos=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            pos=i;
            break;
        }
    }
    int ans2;
    int pos1=pos;
    int ans1=pos/n+(pos%n!=0);
    if(ans1%2==0)//even
    {
        if(pos%n==0)ans2=1;
        else ans2=n-pos%n+1;
    }
    if(ans1%2==1)
    {
        if(pos%n==0)ans2=n;
        else ans2=pos%n;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
