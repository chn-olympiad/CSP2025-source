#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int x=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<=a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            x=i;
            if(x%n==0){
                cout<<x/n<<' ';
            }
            else
                cout<<x/n+1<<' ';

            if((x/n+1)%2==1)
                if(x%n==0)
                    cout<<n;
                else
                    cout<<x%n;
            else
                cout<<2*n-x+1;
            break;
        }

    }


    return 0;
}
