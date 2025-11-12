#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define const constexpr
int32_t main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,ans=0;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        int ac=0,bc=0,cc=0,n2=n/2,maxa=0,maxb=0,maxc=0,ai,bi,ci;
        bool t1=true;
        //sort(a.begin(),a.end()),sort(b.begin(),b.end()),sort(c.begin(),c.end());
        for(int i=0;i<n;i++)
        {
            if(b[i]!=c[i]!=0)
            {
                t1=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            maxb=max(maxb,b[i]);
        }
        for(int i=0;i<n;i++)
        {
            maxc=max(maxc,c[i]);
        }
        if(!t1)
        {
        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i]&&a[i]>c[i]&&ac<n2&&a[i]==maxa)
            {
                ans+=a[i];ac++;a[i]=0;ai=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]>a[i]&&b[i]>c[i]&&bc<n2&&b[i]==maxb)
            {
                ans+=b[i];bc++;b[i]=0;bi=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(c[i]>b[i]&&c[i]>a[i]&&cc<n2&&c[i]==maxc)
            {
                ans+=c[i];cc++;c[i]=0;ci=i;
            }
        }
        }
        else
        {
            int sum=0;
            sort(a.rbegin(),a.rend());
            for(int i=0;i<n2;i++)
            {
                sum+=a[i];
            }
            cout << sum << endl;
            continue;
        }
        cout << ans << endl;
        ans=0;
        
    }
    return 0;
}
