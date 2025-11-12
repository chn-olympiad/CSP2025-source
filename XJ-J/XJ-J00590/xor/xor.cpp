#include<bits/stdc++.h>
using namespace std;
long long n,k,sum;
long long a[(int)5e5+10];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            int num=a[i];
            for(int l=i+1;l<=j;l++) {
                num=num^a[l];
            }
            if(num==k) {
                cout<<i<<" "<<j<<endl;
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
