#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],r,c=1,l=1;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(r==a[i]){
            cout<<c<<" "<<l;
            return 0;
        }
        if(c&1){
            l++;
            if(l>m){
                c++;
                l--;
            }
        }else{
            l--;
            if(l<=0){
                c++;
                l++;
            }
        }
    }
    return 0;
}

// I love you,SYH.
