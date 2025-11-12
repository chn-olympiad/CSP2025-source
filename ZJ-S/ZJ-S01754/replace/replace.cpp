#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;

int n,q;
string a[1010],b[1010];
string fra[2010],frb[2010],ena[2010],enb[2010];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int s=1; s<=q; s++)
    {
        int ans=0;
        string stra,strb;
        cin>>stra>>strb;
        for(int i=1; i<=stra.length(); i++)fra[i]=fra[i-1]+stra[i-1];
        for(int i=stra.length(); i>=1; i--)ena[i]=stra[i-1]+ena[i+1];
        for(int i=1; i<=strb.length(); i++)frb[i]=frb[i-1]+strb[i-1];
        for(int i=strb.length(); i>=1; i--)enb[i]=strb[i-1]+enb[i+1];
        for(int t=1; t<=n; t++)
        {
            for(int i=1; i<=stra.length(); i++)
            {
                if(fra[i-1]!=frb[i-1])break;
                bool flag=true;
                for(int j=i; j<i+a[t].length(); j++)
                {
                    if(stra[j-1]!=a[t][j-i]||b[t][j-i]!=strb[j-1])
                    {
                        flag=false;
                        break;
                    }
                }
                if(ena[i+a[t].length()]==enb[i+a[t].length()]&&flag)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
