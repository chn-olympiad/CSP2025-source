#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5+10;
int a[N],b[N],c[N];
int n;


bool stb;

int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    
    int t;
    int ans =0;
    cin >>t;
    while(t--)
    {
        int suma=0,sumb=0,sumc=0;
        ans=0;
        cin >>n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i]>>b[i]>>c[i];
            if(b[i]!=0)
                stb==1;
        }
        if(n==2)
        {
            cout << max(a[0]+b[1],a[1]+b[0]);
            return 0;
        }

        else if(stb==0)
        {
            sort(a,a+n);
            for(int i=n-1;i>=0;i--)
                ans+=a[i];
        }
    }

    cout << ans;
    return 0;
    
}