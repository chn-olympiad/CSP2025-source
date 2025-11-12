#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,first,x,pos1,pos2;
bool flag=true;
long long a[105];
bool cmp(int x,int y)
{
    return x>y?true:false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        //cout<<a[i];
    }
    first=a[1];
    //cout<<n<<m;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        pos2++;
        if(pos2%n==1)
        {
            pos1++;
            pos2=1;
            flag=!flag;
        }
        //cout<<i<<" "<<a[i]<<" "<<pos1<<" "<<pos2<<endl;
        if(a[i]==first)break;
    }
    if(flag)pos2=n-pos2+1;
    cout<<pos1<<" "<<pos2;
    return 0;
}
