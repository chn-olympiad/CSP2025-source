#include<bits/stdc++.h>
using namespace std;
const int N=510,p=998244353;
long long cnt[N*100];
int l[N],n;
void pianfen()
{
    bool f=1;
    int a=1,b=(n*n-n)/2+n+1,m=n;
    while(m--)
    {
        a*=2;
        a%=p;
    }
    cout<<((long long)a+p-b)%p;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    long long ans=0;
	for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    if(l[n-1]==1)
    {
        pianfen();
        return 0;
    }
    cnt[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=l[i]+1;j<(N*100);j++)
        {
            ans+=cnt[j];
            ans%=p;
        }
        for(int j=(N*100)-1;j>=l[i];j--)
        {
            cnt[j]+=cnt[j-l[i]];
            cnt[j]%=p;
        }
    }
    cout<<ans;
	return 0;
}
