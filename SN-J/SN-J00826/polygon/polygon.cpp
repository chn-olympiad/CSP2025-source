#include<bits/stdc++.h>
using namespace std;
const int N=5005;
using ll=long long;
ll sum,ans;int n;
int a[N];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=0;t<=n-3;t++){
        for(int i=3;i<=n-t;i++){
            int maxn=0;sum=0;
            for(int j=t+1;j<=i+t;j++){
                sum+=a[j];
                if(maxn<a[j])maxn=a[j];
            }
            if(sum>2*maxn)ans++;
        }
    }
    cout<<ans<<endl;
}
