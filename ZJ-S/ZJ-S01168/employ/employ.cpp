#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    string c;
    cin>>c;
    vector<int>d,p;
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        d.push_back(c);
        p.push_back(i);
    }
    int ans=0;
    do
    {
        int lu=0;
        int lian=0;
        for(int i=0;i<n;i++)
        {
            if(d[p[i]]>=lian)lian++;
            else
            {
                if(c[i]=='0')
                {
                    lian++;
                }
                else
                {
                    lu++;
                    lian=0;
                }
            }
        }
        ans+=lu>=m;
    } while (next_permutation(p.begin(),p.end()));
    cout<<ans;
}