#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n*m);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int x=a[0];
    int sum;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;++i){
        if(a[i]==x){
            sum=i+1;
            break;
        }
    }
    int c;
    if(sum<=n) c=1;
    else if(sum%n==0) c=sum/n;
    else c=sum/m +1;
    int r=5;
    if(sum==n||sum==n+1||sum==3*n||sum==3*n+1||sum==5*n||sum==5*n+1||sum==7*n||sum==7*n+1||sum==9*n||sum==9*n+1) r=n;
    else if(sum<n) r=sum;
    cout<<c<<" "<<r;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
