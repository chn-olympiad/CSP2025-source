#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int b[1<<21];
int n,k,c=0,last=0,ans=0;
int main()
{
    memset(b,0xff,sizeof b);
    b[0]=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        c^=a;
        if(b[c^k]>=last)
        {
            ans++;
            last=i;
        }
        b[c]=i;
    }
    cout<<ans;
	return 0;
}
