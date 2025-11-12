#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+10;

int a[N][5],b[N],val[N],cnt[5],tot,n,T;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        cnt[1]=cnt[2]=cnt[3]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int t=max(max(a[i][1],a[i][2]),a[i][3]);
            ans+=t;
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]==t)
                {
                    b[i]=j;
                    cnt[j]++;
                    break;
                }
            }
        }
        int pos=-1;
        for(int i=1;i<=3;i++) if(cnt[i]>n/2) pos=i;
        if(pos>0)
        {
            tot=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]==pos)
                {
                    int t=max(a[i][pos%3+1],a[i][(pos+1)%3+1]);
                    val[++tot]=a[i][pos]-t;
                }
            }
            sort(val+1,val+tot+1);
            for(int i=1;i<=cnt[pos]-n/2;i++) ans-=val[i];
        }
        cout << ans << '\n';
    }
    return 0;
}