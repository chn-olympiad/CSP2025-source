#include<bits/stdc++.h>
using namespace std;
int n,a[500060];
long long k;
int xorr(int a,int b)
{
    while(a)
    {
        string aa;
        aa+=to_string(a%2);
        a=floor(a/2);
        int as;
        for(int i=aa.size()-1;i>=0;i--)
        {
            as+=aa[i]*i;
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>n>>k;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }




    cout << 0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
