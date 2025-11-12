#include<bits/stdc++.h>
using namespace std;
int n ,ans;
string cd;
long long a[10007];
const long long Q=998244353;
void c(int wei,int bef,int youc)
{
    if(wei>n||youc>=n) return;
    for(int i=max(youc+1,wei);i<=n;i++)
    {
        cd=to_string(10*bef+i);
        //cout << cd<< " ";
        if(cd.size()>=3)
        {
            long long maxx=-1,sum=0;
            for(int j=0;j<cd.size();j++)
            {
                long long w=cd[j]-48;
                maxx=max(maxx,a[w]);
                sum+=a[w];
            }

            if(sum>maxx+maxx)
            {
                ans++;
                //cout <<cd<<" "<< maxx<<" "<<sum<< "  ";
            }

        }
        c(wei+1,10*bef+i,i);
    }

//卡20

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;

    for(auto i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    c(1,0,0);
    cout <<ans%Q;




    fclose(stdin);
    fclose(stdout);
    return 0;
}
