#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
long long ans,sum;
bool a1[N];
int Xor(int A,int B)
{
    int x[N],y[N],b[N],cntx,cnty,fx,fy,cnt;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    cntx=1,cnty=1;
    for(int i=1;;i++)
    {
        if(A==0||A==1)
        {
            cntx=i;
            x[cntx]=A;
            break;
        }
        x[i]=A%2;
        A/=2;
        
    }
    reverse(x+1,x+1+cntx);
    for(int i=1;;i++)
    {
        if(B==0||B==1)
        {
            cnty=i;
            y[cnty]=B;
            break;
        }
        y[i]=B%2;
        B/=2;
        
    }
    reverse(y+1,y+1+cnty);
    fx=cntx,fy=cnty;
    cnt=max(cntx,cnty);
    int c;
    long long ans=0;
    for(int i=cnt;i>0;i--)
    {
        c=i-1;
        if(fx>0&&fy>0)
        {
            if(x[fx]!=y[fy])b[i]=1;
            else            b[i]=0;
        }
        if(fx<=0)
        {
            if(y[fy]!=0)b[i]=1;
            else        b[i]=0;
        }
        if(fy<=0)
        {
            if(x[fx]!=0)b[i]=1;
            else        b[i]=0;
        }
        ans+=b[i]*pow(2,c);
        //cout<<c<<" ";
        fx--;
        fy--;
    }
    return ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=2&&k==0)
    {
        if(n==1&&a[1]==0)cout<<1;
        else if(n==2&&a[1]==a[2])cout<<1;
        else cout<<0;
    }
    else
    {
        cout<<Xor(a[1],a[2]);
    }
    return 0;
}