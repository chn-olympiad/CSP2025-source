#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p = 591601531,b = 131;
ll n,q,pw[5000010],ht1[5000010],ht2[5000010],hsz[200010];
vector<ll> h1[200010],h2[200010];
string s1,s2;
struct difs
{
    ll l,r,id;
    bool operator<(const difs &x) const
    {
        return r-l+1<x.r-x.l+1;
    }
}df[200010];
ll hsh(ll h[],int l,int r)
{
    return (h[r]-h[l-1]*pw[r-l+1]%p+p)%p;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1;i <= 5000000;i++) pw[i] = pw[i-1]*b%p;
    for (int i = 1;i <= n;i++)
    {
        cin >> s1;
        h1[i].push_back(0);
        for (int j = 0;j < s1.size();j++)
        {
            h1[i].push_back((h1[i][j]*b%p+s1[j])%p);
        }
        cin >> s2;
        h2[i].push_back(0);
        for (int j = 0;j < s2.size();j++)
        {
            h2[i].push_back((h2[i][j]*b%p+s2[j])%p);
        }
        if (h1[i][s1.size()] == h2[i][s2.size()])
        {
            i--; n--;
            continue;
        }
        df[i].l = 1; df[i].r = s1.size(); df[i].id = i; hsz[i] = s1.size();
        for (int j = 0;j < s1.size()-1;j++)
            if (s1[j] == s2[j] && s1[j+1] != s2[j+1])
            {
                df[i].l = j+1+1;
                break;
            }
        for (int j = s2.size()-1;j;j--)
            if (s1[j] == s2[j] && s1[j-1] != s2[j-1])
            {
                df[i].r = j;
                break;
            }
    }
    sort(df+1,df+n+1);
    // for (int i = 1;i <= n;i++) cout << df[i].l << " " << df[i].r << " " << df[i].id << "\n";
    // return 0;
    while(q--)
    {
        cin >> s1 >> s2; int res = 0;
        if (s1.size() != s2.size())
        {
            cout << "0\n";
            continue;
        }
        ht1[0] = ht2[0] = 0;
        for (int i = 0;i < s1.size();i++)
        {
            ht1[i+1] = (ht1[i]*b%p+s1[i])%p;
            ht2[i+1] = (ht2[i]*b%p+s2[i])%p;
        }
        int l = 1,r = s1.size(),mid;
        int dl = 1,dr = s1.size(),pos = -1;
        while(l <= r)
        {
            mid = l+r>>1;
            if (ht1[mid] != ht2[mid])
            {
                dl = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        l = 1; r = s1.size();
        while(l <= r)
        {
            mid = l+r>>1;
            if (hsh(ht1,mid,s1.size()) != hsh(ht2,mid,s1.size()))
            {
                dr = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        ll hst1 = hsh(ht1,dl,dr),hst2 = hsh(ht2,dl,dr);
        l = 1; r = n;
        while(l <= r)
        {
            mid = l+r>>1;
            if (df[mid].r-df[mid].l+1 >= dr-dl+1)
            {
                pos = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        // cout << dl << " " << dr << " " << pos << "\n";
        if (pos == -1 || df[pos].r-df[pos].l+1 > dr-dl+1)
        {
            cout << "0\n";
            continue;
        }
        while(pos <= n && df[pos].r-df[pos].l+1 == dr-dl+1)
        {
            int dfl = df[pos].l,dfr = df[pos].r,dfi = df[pos].id;
            if ((h1[dfi][dfr]-h1[dfi][dfl-1]*pw[dfr-dfl+1]%p+p)%p == hst1 && (h2[dfi][dfr]-h2[dfi][dfl-1]*pw[dfr-dfl+1]%p+p)%p == hst2 && dl-dfl+1 > 0 && dr+hsz[dfi]-dfr <= s1.size())
            {
                if (h1[dfi][hsz[dfi]] == hsh(ht1,dl-dfl+1,dr+hsz[dfi]-dfr)) res++;
            }
            pos++;
        }
        cout << res << "\n";
    }
    return 0;
}