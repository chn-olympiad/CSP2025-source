#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,arr[500005],ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sum=arr[i];
            for(int p=i+1;p<=j;p++)
            {
                sum=sum^arr[p];
            }
            if(sum==k)
            {
                ans++;
                i=j+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
